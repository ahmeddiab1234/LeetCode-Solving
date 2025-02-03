# https://leetcode.com/problems/rearrange-products-table/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    df_long = products.melt(id_vars=["product_id"], var_name="store", value_name="price")
    df_long.dropna(subset=["price"], inplace=True)
    return df_long



