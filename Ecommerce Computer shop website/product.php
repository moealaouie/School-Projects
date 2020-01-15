<?php
/**
 * product.php
 *
 * Project 2
 *
 * @category   Project
 * @package    Project 2
 * @author     Mohamed Alaouie <mhalaouie@hawkmail.hfcc.edu
 * @version    2019.12.10
 * @link       https://cislinux.hfcc.edu/~mhalaouie/cis222/Project2/product.php
 */

if (isset($_GET['id'])) {
	// Connect to the MySQL database  
require "storescripts/connect_to_mysql.php";

	$id = preg_replace('#[^0-9]#i', '', $_GET['id']);

	$sql = "SELECT * FROM products WHERE product_id='$id' LIMIT 1";
	$result = $mysqli->query($sql);
    if ($result->num_rows > 0) {

		while($row = $result->fetch_assoc()){
            $product_name = $row["product_name"];
            $product_price = $row["product_price"];
            $product_image = $row["product_image"];
            $product_description = $row["product_description"];
			 $date_added = strftime("%b %d, %Y", strtotime($row["date_added"]));
         }
		 
	} else {
        echo "That item does not exist.";
        exit();
    }

} else {
	echo "Error 404 Page not found";
	exit();
}
$mysqli->close();
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo $product_name; ?></title>
<link rel="stylesheet" href="style/style.css" type="text/css" media="screen" />
</head>
<body>
<div align="center" id="mainWrapper">
  <?php include_once("template_header.php");?>
  <div id="pageContent">
  <table width="100%" border="0" cellspacing="0" cellpadding="15">
  <tr>
    <td width="19%" valign="top"><img src="inventory_images/<?php echo $product_image; ?>" width="142" height="188" alt="<?php echo $product_name; ?>" /><br />
      <a href="inventory_images/<?php echo $product_image; ?>">View Full Size Image</a></td>
    <td width="81%" valign="top"><h3><?php echo $product_name; ?></h3>
      <p><?php echo "$".$product_price; ?><br />
        <br />
       <br />
<br />
        <?php echo $product_description; ?>
<br />
        </p>
      <form id="form1" name="form1" method="post" action="cart.php">
        <input type="hidden" name="pid" id="pid" value="<?php echo $id; ?>" />
        <input type="submit" name="button" id="button" value="Add to Shopping Cart" />
      </form>
      </td>
    </tr>
</table>
  </div>
  <?php include_once("template_footer.php");?>
</div>
</body>
</html>