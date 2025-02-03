# https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata

import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    order_counts = orders.groupby('customer_number').size().reset_index(name='count')
    max_orders = order_counts['count'].max()
    result = order_counts[order_counts['count'] == max_orders][['customer_number']]
    return result


