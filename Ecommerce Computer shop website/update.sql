Could not figure out how to create the export file in phpstorm so i just copied the sql scripts






INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (1, 'Rolando	Chambers', '92 Cross Street
Decatur, GA 30030', '(787) 699-7229', 'RC@gmail.com', 'sss', '', '');
INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (2, 'Jonathan Mason', '119 Wellington Lane
Knoxville, TN 37918', '(982) 972-8591', 'joe@gmail.com', 'sss', '', '');
INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (3, 'Diana Barton', '8983 Lees Creek Ave.
Marshfield, WI 54449', '(306) 959-1040', 'Diana@gmail.com', 'sss', '', '');
INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (4, 'Taylor Wade', '7058 Manhattan Drive
Santa Cruz, CA 95060', '(838) 476-1089', 'tw@gmailcom', 'hello', '', '');
INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (62, 'asdasd', '', '2323', 'asdsa', 'asdasd', '', '');
INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (63, 'asdasd', '', '2323', 'asdsa', 'asdasd', '', '');
INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (64, 'sadasd', '', 'asdasd', 'asdasd', 'asdasd', '', '');
INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (65, 'Mohamed Ali Alaouie', '', '3132650881', 'Moealaouie@gmail.com', 'asdasd', '', '');
INSERT INTO mhalaouie.customers (customer_id, customer_name, customer_address, customer_phone, customer_email, customer_feedback, customer_username, customer_password) VALUES (66, '1213123', '', 'aswdas', 'asdasd', 'asdas', '', '');





UPDATE mhalaouie.customers SET customer_name = 'Rolando	Chambers', customer_address = '92 Cross Street
Decatur, GA 30030', customer_phone = '(787) 699-7229', customer_email = 'RC@gmail.com', customer_feedback = 'sss', customer_username = '', customer_password = '' WHERE customer_id = 1;
UPDATE mhalaouie.customers SET customer_name = 'Jonathan Mason', customer_address = '119 Wellington Lane 
Knoxville, TN 37918', customer_phone = '(982) 972-8591', customer_email = 'joe@gmail.com', customer_feedback = 'sss', customer_username = '', customer_password = '' WHERE customer_id = 2;
UPDATE mhalaouie.customers SET customer_name = 'Diana Barton', customer_address = '8983 Lees Creek Ave. 
Marshfield, WI 54449', customer_phone = '(306) 959-1040', customer_email = 'Diana@gmail.com', customer_feedback = 'sss', customer_username = '', customer_password = '' WHERE customer_id = 3;
UPDATE mhalaouie.customers SET customer_name = 'Taylor Wade', customer_address = '7058 Manhattan Drive 
Santa Cruz, CA 95060', customer_phone = '(838) 476-1089', customer_email = 'tw@gmailcom', customer_feedback = 'hello', customer_username = '', customer_password = '' WHERE customer_id = 4;
UPDATE mhalaouie.customers SET customer_name = 'asdasd', customer_address = '', customer_phone = '2323', customer_email = 'asdsa', customer_feedback = 'asdasd', customer_username = '', customer_password = '' WHERE customer_id = 62;
UPDATE mhalaouie.customers SET customer_name = 'asdasd', customer_address = '', customer_phone = '2323', customer_email = 'asdsa', customer_feedback = 'asdasd', customer_username = '', customer_password = '' WHERE customer_id = 63;
UPDATE mhalaouie.customers SET customer_name = 'sadasd', customer_address = '', customer_phone = 'asdasd', customer_email = 'asdasd', customer_feedback = 'asdasd', customer_username = '', customer_password = '' WHERE customer_id = 64;
UPDATE mhalaouie.customers SET customer_name = 'Mohamed Ali Alaouie', customer_address = '', customer_phone = '3132650881', customer_email = 'Moealaouie@gmail.com', customer_feedback = 'asdasd', customer_username = '', customer_password = '' WHERE customer_id = 65;
UPDATE mhalaouie.customers SET customer_name = '1213123', customer_address = '', customer_phone = 'aswdas', customer_email = 'asdasd', customer_feedback = 'asdas', customer_username = '', customer_password = '' WHERE customer_id = 66;


CREATE TABLE `Cart` (
  `Cart_id` int(11) NOT NULL AUTO_INCREMENT,
  `Customer_Id` int(11) NOT NULL,
  `Product_Id` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  `price` double NOT NULL,
  `dateAdded` datetime NOT NULL,
  PRIMARY KEY (`Cart_id`),
  KEY `Cart_customers_customer_id_fk` (`Customer_Id`),
  KEY `Cart_products_product_id_fk` (`Product_Id`),
  CONSTRAINT `Cart_customers_customer_id_fk` FOREIGN KEY (`Customer_Id`) REFERENCES `customers` (`customer_id`),
  CONSTRAINT `Cart_products_product_id_fk` FOREIGN KEY (`Product_Id`) REFERENCES `products` (`product_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci

CREATE TABLE `Order` (
  `Order_id` int(11) NOT NULL AUTO_INCREMENT,
  `Customer_id` int(11) NOT NULL,
  `totalPrice` double NOT NULL,
  `datePurchased` datetime NOT NULL,
  `dateShipped` datetime NOT NULL,
  `dateCanceled` datetime NOT NULL,
  PRIMARY KEY (`Order_id`),
  KEY `Order_customers_customer_id_fk` (`Customer_id`),
  CONSTRAINT `Order_customers_customer_id_fk` FOREIGN KEY (`Customer_id`) REFERENCES `customers` (`customer_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci

CREATE TABLE `Order_item` (
  `Item_id` int(11) NOT NULL AUTO_INCREMENT,
  `Order_id` int(11) NOT NULL,
  `Product_id` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  `Price` double NOT NULL,
  `datePurchased` datetime NOT NULL,
  PRIMARY KEY (`Item_id`),
  KEY `Order_item_Order_Order_id_fk` (`Order_id`),
  KEY `Order_item_products_product_id_fk` (`Product_id`),
  CONSTRAINT `Order_item_Order_Order_id_fk` FOREIGN KEY (`Order_id`) REFERENCES `Order` (`Order_id`),
  CONSTRAINT `Order_item_products_product_id_fk` FOREIGN KEY (`Product_id`) REFERENCES `products` (`product_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci

CREATE TABLE `products` (
  `product_id` int(11) NOT NULL AUTO_INCREMENT,
  `product_name` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `product_description` text COLLATE utf8mb4_unicode_ci,
  `product_price` decimal(13,2) NOT NULL,
  `product_quantity` int(11) DEFAULT NULL,
  `product_image` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `product_type` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `date_added` datetime NOT NULL,
  PRIMARY KEY (`product_id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci

INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (1, 'Alienware Laptop', 'gaming laptop...ooooh', 800.00, 7, 'alienpc.jpg', 'Hardware', null);
INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (2, 'HP Monitor', 'A monitor...WOW', 150.00, 18, 'hp.png', 'Hardware', null);
INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (3, 'HyperX Cloud II', 'Best selling headset...OMG', 119.00, 30, 'hyp2.jpg', 'Accessories', null);
INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (4, '8GB RAM', 'Random Access Memory...YEET', 50.00, 8239, 'ram.jpg', 'Hardware', null);
INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (5, 'Asus Rog Tower', 'An absolute beast! I would buy it if i were you', 1800.00, 3, 'rogtower.jpg', 'Hardware', null);
INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (6, 'GeForce 1080 Graphics Card', 'Graphics card for gaming', 150.00, 50, 'geforce1080.jpg', 'Hardware', null);
INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (7, 'HyperX Cloud II', 'Best selling headset...OMG', 119.00, 30, 'hyp2.jpg', 'Accessories', null);
INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (8, 'HP Monitor', 'A monitor...WOW', 150.00, 18, 'hp.png', 'Hardware', null);
INSERT INTO mhalaouie.products (product_id, product_name, product_description, product_price, product_quantity, product_image, product_type, date_added) VALUES (9, 'GeForce 1080 Graphics Card Deluxe', 'Graphics card for gaming deluxe edition', 250.00, 50, 'geforce1080.jpg', 'Hardware', null);

UPDATE mhalaouie.products SET product_name = 'Alienware Laptop', product_description = 'gaming laptop...ooooh', product_price = 800.00, product_quantity = 7, product_image = 'alienpc.jpg', product_type = 'Hardware', date_added = null WHERE product_id = 1;
UPDATE mhalaouie.products SET product_name = 'HP Monitor', product_description = 'A monitor...WOW', product_price = 150.00, product_quantity = 18, product_image = 'hp.png', product_type = 'Hardware', date_added = null WHERE product_id = 2;
UPDATE mhalaouie.products SET product_name = 'HyperX Cloud II', product_description = 'Best selling headset...OMG', product_price = 119.00, product_quantity = 30, product_image = 'hyp2.jpg', product_type = 'Accessories', date_added = null WHERE product_id = 3;
UPDATE mhalaouie.products SET product_name = '8GB RAM', product_description = 'Random Access Memory...YEET', product_price = 50.00, product_quantity = 8239, product_image = 'ram.jpg', product_type = 'Hardware', date_added = null WHERE product_id = 4;
UPDATE mhalaouie.products SET product_name = 'Asus Rog Tower', product_description = 'An absolute beast! I would buy it if i were you', product_price = 1800.00, product_quantity = 3, product_image = 'rogtower.jpg', product_type = 'Hardware', date_added = null WHERE product_id = 5;
UPDATE mhalaouie.products SET product_name = 'GeForce 1080 Graphics Card', product_description = 'Graphics card for gaming', product_price = 150.00, product_quantity = 50, product_image = 'geforce1080.jpg', product_type = 'Hardware', date_added = null WHERE product_id = 6;
UPDATE mhalaouie.products SET product_name = 'HyperX Cloud II', product_description = 'Best selling headset...OMG', product_price = 119.00, product_quantity = 30, product_image = 'hyp2.jpg', product_type = 'Accessories', date_added = null WHERE product_id = 7;
UPDATE mhalaouie.products SET product_name = 'HP Monitor', product_description = 'A monitor...WOW', product_price = 150.00, product_quantity = 18, product_image = 'hp.png', product_type = 'Hardware', date_added = null WHERE product_id = 8;
UPDATE mhalaouie.products SET product_name = 'GeForce 1080 Graphics Card Deluxe', product_description = 'Graphics card for gaming deluxe edition', product_price = 250.00, product_quantity = 50, product_image = 'geforce1080.jpg', product_type = 'Hardware', date_added = null WHERE product_id = 9;