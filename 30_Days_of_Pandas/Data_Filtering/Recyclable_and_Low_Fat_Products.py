# https://leetcode.com/problems/recyclable-and-low-fat-products/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata

import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    new_df = products[(products['low_fats']=='Y' )& (products['recyclable'] == 'Y')]
    return new_df[['product_id']]



