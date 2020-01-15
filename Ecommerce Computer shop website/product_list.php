<?php
/**
 * product_list.php
 *
 * Project 2
 *
 * @category   Project
 * @package    Project 2
 * @author     Mohamed Alaouie <mhalaouie@hawkmail.hfcc.edu
 * @version    2019.12.10
 * @link       https://cislinux.hfcc.edu/~mhalaouie/cis222/Project2/product_list.php
 */
error_reporting(E_ALL);
ini_set('display_errors', '1');
?>
<?php
// Run a select query to get my letest 6 items
// Connect to the MySQL database
require "storescripts/connect_to_mysql.php";
$dynamicList = "";
$sql = 'SELECT * FROM products';
$result = $mysqli->query($sql);
//$productCount = $result->num_rows; // count the output amount

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()){
        $product_id = $row["product_id"];
        $product_name = $row["product_name"];
        $product_price = $row["product_price"];
        $product_image = $row["product_image"];
        $date_added = strftime("%b %d, %Y", strtotime($row["date_added"]));
        $dynamicList .= '<table width="100%" border="0" cellspacing="0" cellpadding="6">
        <tr>
          <td width="17%" valign="top"><a href="product.php?id=' . $product_id . '"><img style="border:#666 1px solid;" src="inventory_images/'.$product_image.'" alt="' . $product_name . '" width="77" height="102" border="1" /></a></td>
          <td width="83%" valign="top">' . $product_name . '<br />
            $' . $product_price . '<br />
            <a href="product.php?id=' . $product_id . '">View Product Details</a></td>
        </tr>
      </table>';
    }
} else {
    $dynamicList = "We have no products listed in our store yet";
}
$mysqli->close();
?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Store Home Page</title>
    <link rel="stylesheet" href="style/style.css" type="text/css" media="screen" />
</head>
<body>
<div align="center" id="mainWrapper">
    <?php include_once("template_header.php");?>
    <div id="pageContent">
                    <p><?php echo $dynamicList; ?><br />

    </div>
    <?php include_once("template_footer.php");?>
</div>
</body>
</html>