# https://leetcode.com/problems/count-occurrences-in-text?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def count_occurrences(files: pd.DataFrame) -> pd.DataFrame:
    bull_count = (files['content'].str.count(r'\bbull\b')).sum()
    bear_count = (files['content'].str.count(r'\bbear\b')).sum()
    
    return pd.DataFrame({'word': ['bull', 'bear'], 'count': [bull_count, bear_count]})


