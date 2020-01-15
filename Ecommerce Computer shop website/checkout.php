<?php
/**
 * checkout.php
 *
 * Project 2
 *
 * @category   Project
 * @package    Project 2
 * @author     Mohamed Alaouie <mhalaouie@hawkmail.hfcc.edu
 * @version    2019.12.10
 * @link       https://cislinux.hfcc.edu/~mhalaouie/cis222/Project2/checkout.php
 */
error_reporting(E_ALL);
ini_set('display_errors', '1');
?>
<?php

require "storescripts/connect_to_mysql.php";
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

        <h3>Billing Address</h3>
        <label for="fname"><i class="fa fa-user"></i> Full Name</label>
        <input type="text" id="fname" name="firstname" placeholder="John M. Doe">
        <br />
        <label for="email"><i class="fa fa-envelope"></i> Email</label>
        <input type="text" id="email" name="email" placeholder="john@example.com">
        <br />
        <label for="adr"><i class="fa fa-address-card-o"></i> Address</label>
        <input type="text" id="adr" name="address" placeholder="542 W. 15th Street">
        <br />
        <label for="city"><i class="fa fa-institution"></i> City</label>
        <input type="text" id="city" name="city" placeholder="New York">
        <br />
        <label for="state">State</label>
        <input type="text" id="state" name="state" placeholder="NY">
        <br />
        <label for="zip">Zip</label>
        <input type="text" id="zip" name="zip" placeholder="10001">
        <br />
        <br />
        <br />
        <h3>Payment</h3>
        <label for="cname">Name on Card</label>
        <input type="text" id="cname" name="cardname" placeholder="John More Doe">
        <br />
        <label for="ccnum">Credit card number</label>
        <input type="text" id="ccnum" name="cardnumber" placeholder="1111-2222-3333-4444">
        <br />
        <label for="expmonth">Exp Month</label>
        <input type="text" id="expmonth" name="expmonth" placeholder="September">
        <br />
        <label for="expyear">Exp Year</label>
        <input type="text" id="expyear" name="expyear" placeholder="2018">
        <br />
        <label for="cvv">CVV</label>
        <input type="text" id="cvv" name="cvv" placeholder="352">
        <br />


<label>
    <input type="checkbox" checked="checked" name="sameadr"> Shipping address same as billing
</label>
        <br />
<input type="submit" value="Submit Payment" class="btn">
</form>
//<?php
  //      if(isset($_POST['submit'])){ header("Location: cart.php?cmd=emptycart");
        ?>


    </div>
    <?php include_once("template_footer.php");?>
</div>
</body>
</html>