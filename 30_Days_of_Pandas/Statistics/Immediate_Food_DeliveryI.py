# https://leetcode.com/problems/immediate-food-delivery-i/



import pandas as pd

def food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    immediate_count = (delivery['order_date'] == delivery['customer_pref_delivery_date']).sum()
    immediate_percentage = round(100 * immediate_count / len(delivery), 2)
    return pd.DataFrame({'immediate_percentage': [immediate_percentage]})

