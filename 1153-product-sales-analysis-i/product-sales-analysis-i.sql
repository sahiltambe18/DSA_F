# Write your MySQL query statement below

select product_name, year, price from sales
left join Product on Product.product_id = sales.product_id;