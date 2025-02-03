# https://leetcode.com/problems/ads-performance/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def ads_performance(ads: pd.DataFrame) -> pd.DataFrame:
    clicks = ads[ads['action'] == 'Clicked'].groupby('ad_id').size().reset_index(name='clicked')
    views = ads[ads['action'] == 'Viewed'].groupby('ad_id').size().reset_index(name='viewed')

    all_ads = ads[['ad_id']].drop_duplicates()

    result = all_ads.merge(views, on='ad_id', how='left').merge(clicks, on='ad_id', how='left')
    result['ctr'] = round(100 * (result['clicked'] / (result['viewed'] + result['clicked']) ), 2)
    result['ctr'] = result['ctr'].fillna(0)
    
    result = result[['ad_id', 'ctr']].sort_values(by=['ctr', 'ad_id'], ascending=[False, True])

    return result


