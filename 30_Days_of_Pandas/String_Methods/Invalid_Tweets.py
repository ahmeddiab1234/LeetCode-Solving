# https://leetcode.com/problems/invalid-tweets/?envType=study-plan-v2&envId=30-days-of-pandas

import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    new_df = tweets[tweets['content'].apply(len) > 15]
    return new_df[['tweet_id']]



