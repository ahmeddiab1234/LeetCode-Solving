# https://leetcode.com/problems/big-countries/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata

import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    new_df = world[(world['population']>=25000000) | ( world['area'] >=3000000)]
    return new_df[['name', 'population', 'area']]




