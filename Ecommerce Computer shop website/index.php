<?php 
/**
 * index.php
 *
 * Project 2
 *
 * @category   Project
 * @package    Project 2
 * @author     Mohamed Alaouie <mhalaouie@hawkmail.hfcc.edu
 * @version    2019.12.10
 * @link       https://cislinux.hfcc.edu/~mhalaouie/cis222/Project2/index.php
 */
error_reporting(E_ALL);
ini_set('display_errors', '1');
?>
<?php 
// Run a select query to get my letest 6 items
// Connect to the MySQL database  
require "storescripts/connect_to_mysql.php";
$dynamicList = "";
$sql = 'SELECT * FROM products LIMIT 6 ';
$result = $mysqli->query($sql);

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
  <table width="100%" border="0" cellspacing="0" cellpadding="10">
  <tr>
    <td width="32%" valign="top"><h3>Hello Valued Customer!</h3>
      <p>Welcome to DYNAMOE's Computer Shop! Home of all your hardware and computer accessory needs! We offer a wide variety of products ranging from high end computers to standard keyboards and headsets. We also offer services for any repairs or hard drive cleanups. Check out our products page for all of our latest products. Happy Shopping!<br />
        <a href="https://www.youtube.com/watch?v=QlsSzsQsX0M" target="_blank">Click to view our latest advertisement</a> </p>
        <br />
        <br /></p></td>
    <td width="35%" valign="top"><h3>Latest Products!</h3>
      <p><?php echo $dynamicList; ?><br />
        </p>
      <p><br />
      </p></td>
    <td width="33%" valign="top"><h3>About us</h3>
      <p>If you are looking for an expert onsite computer or laptop service and repair company then you have found it! We have over 25 years experience in computer, laptop repair and service.

          Call us to schedule an appoinment. (313) 123-4567 Dearborn or (734) 321-7654 Canton</p></td>
  </tr>
</table>

  </div>
  <?php include_once("template_footer.php");?>
</div>
</body>
</html>