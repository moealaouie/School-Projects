<?php
/**
 * cart.php
 *
 * Project 2
 *
 * @category   Project
 * @package    Project 2
 * @author     Mohamed Alaouie <mhalaouie@hawkmail.hfcc.edu
 * @version    2019.12.10
 * @link       https://cislinux.hfcc.edu/~mhalaouie/cis222/Project2/cart.php
 */

session_start();

error_reporting(E_ALL);
ini_set('display_errors', '1');
// Connect to the MySQL database
include "storescripts/connect_to_mysql.php";
?>
<?php
if (isset($_POST['pid'])) {
    $pid = $_POST['pid'];
    $wasFound = false;
    $i = 0;
    if (!isset($_SESSION["cart_array"]) || count($_SESSION["cart_array"]) < 1) {
        $_SESSION["cart_array"] = array(0 => array("item_id" => $pid, "quantity" => 1));
    } else {
        foreach ($_SESSION["cart_array"] as $each_item) {
            $i++;
            while (list($key, $value) = each($each_item)) {
                if ($key == "item_id" && $value == $pid) {
                    array_splice($_SESSION["cart_array"], $i-1, 1, array(array("item_id" => $pid, "quantity" => $each_item['quantity'] + 1)));
                    $wasFound = true;
                }
            }
        }
        if ($wasFound == false) {
            array_push($_SESSION["cart_array"], array("item_id" => $pid, "quantity" => 1));
        }
    }
    header("location: cart.php");
    exit();
}
?>
<?php

if (isset($_GET['cmd']) && $_GET['cmd'] == "emptycart") {
    unset($_SESSION["cart_array"]);
}
?>
<?php



if (isset($_POST['item_to_adjust']) && $_POST['item_to_adjust'] != "") {
    // execute some code
    $item_to_adjust = $_POST['item_to_adjust'];
    $quantity = $_POST['quantity'];
    $quantity = preg_replace('#[^0-9]#i', '', $quantity); // filter everything but numbers
    if ($quantity >= 100) { $quantity = 99; }
    if ($quantity < 1) { $quantity = 1; }
    if ($quantity == "") { $quantity = 1; }
    $i = 0;
    foreach ($_SESSION["cart_array"] as $each_item) {
        $i++;
        while (list($key, $value) = each($each_item)) {
            if ($key == "item_id" && $value == $item_to_adjust) {
                array_splice($_SESSION["cart_array"], $i-1, 1, array(array("item_id" => $item_to_adjust, "quantity" => $quantity)));
            }
    }
    }
}
?>
<?php
if (isset($_POST['index_to_remove']) && $_POST['index_to_remove'] != "") {
    $key_to_remove = $_POST['index_to_remove'];
    if (count($_SESSION["cart_array"]) <= 1) {
        unset($_SESSION["cart_array"]);
    } else {
        unset($_SESSION["cart_array"]["$key_to_remove"]);
        sort($_SESSION["cart_array"]);
    }
}
?>
<?php
$cartOutput = "";
$cartTotal = "";
$pp_checkout_btn = '';
$product_id_array = '';
if (!isset($_SESSION["cart_array"]) || count($_SESSION["cart_array"]) < 1) {
    $cartOutput = "<h2 align='center'>Your shopping cart is empty</h2>";
} else {

    $i = 0;
    foreach ($_SESSION["cart_array"] as $each_item) {
        $item_id = $each_item['item_id'];
        $sql = "SELECT * FROM products WHERE product_id='$item_id' LIMIT 1";
        $result = $mysqli->query($sql);
        if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()){
            $product_name = $row["product_name"];
            $product_price = $row["product_price"];
            $product_description = $row["product_description"];
            $product_image = $row["product_image"];
        }}else{echo "error"; exit();}
        $pricetotal = $product_price * $each_item['quantity'];
        $cartTotal = $pricetotal + $cartTotal;
        setlocale(LC_MONETARY, "en_US");
        $pricetotal = money_format("%10.2n", $pricetotal);

        $x = $i + 1;
        $product_id_array .= "$item_id-".$each_item['quantity'].",";
        $cartOutput .= "<tr>";
        $cartOutput .= '<td><a href="product.php?id=' . $item_id . '">' . $product_name . '</a><br /><img src="inventory_images/' . $product_image . '" alt="' . $product_name. '" width="40" height="52" border="1" /></td>';
        $cartOutput .= '<td>' . $product_description . '</td>';
        $cartOutput .= '<td>$' . $product_price . '</td>';
        $cartOutput .= '<td><form action="cart.php" method="post">
		<input name="quantity" type="text" value="' . $each_item['quantity'] . '" size="1" maxlength="2" />
		<input name="adjustBtn' . $item_id . '" type="submit" value="change" />
		<input name="item_to_adjust" type="hidden" value="' . $item_id . '" />
		</form></td>';
        //$cartOutput .= '<td>' . $each_item['quantity'] . '</td>';
        $cartOutput .= '<td>' . $pricetotal . '</td>';
        $cartOutput .= '<td><form action="cart.php" method="post"><input name="deleteBtn' . $item_id . '" type="submit" value="X" /><input name="index_to_remove" type="hidden" value="' . $i . '" /></form></td>';
        $cartOutput .= '</tr>';
        $i++;
    }
    setlocale(LC_MONETARY, "en_US");
    $cartTotal = money_format("%10.2n", $cartTotal);
    $cartTotal = "<div style='font-size:18px; margin-top:12px;' align='right'>Cart Total : ".$cartTotal." USD</div>";

}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Your Cart</title>
    <link rel="stylesheet" href="style/style.css" type="text/css" media="screen" />
</head>
<body>
<div align="center" id="mainWrapper">
    <?php include_once("template_header.php");?>
    <div id="pageContent">
        <div style="margin:24px; text-align:left;">

            <br />
            <table width="100%" border="1" cellspacing="0" cellpadding="6">
                <tr>
                    <td width="18%" bgcolor="#C5DFFA"><strong>Product</strong></td>
                    <td width="45%" bgcolor="#C5DFFA"><strong>Product Description</strong></td>
                    <td width="10%" bgcolor="#C5DFFA"><strong>Unit Price</strong></td>
                    <td width="9%" bgcolor="#C5DFFA"><strong>Quantity</strong></td>
                    <td width="9%" bgcolor="#C5DFFA"><strong>Total</strong></td>
                    <td width="9%" bgcolor="#C5DFFA"><strong>Remove</strong></td>
                </tr>
                <?php echo $cartOutput; ?>
                <!-- <tr>
                   <td>&nbsp;</td>
                   <td>&nbsp;</td>
                   <td>&nbsp;</td>
                   <td>&nbsp;</td>
                   <td>&nbsp;</td>
                   <td>&nbsp;</td>
                 </tr> -->
            </table>
            <?php echo $cartTotal; ?>
            <br />
            <br />
            <a href ="checkout.php">Checkout</a>
            <br />
            <br />
            <a href="cart.php?cmd=emptycart">Click Here to Empty Your Shopping Cart</a>
        </div>
        <br />
    </div>
    <?php include_once("template_footer.php");?>
</div>
</body>
</html>