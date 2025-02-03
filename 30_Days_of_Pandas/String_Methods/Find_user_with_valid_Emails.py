# https://leetcode.com/problems/find-users-with-valid-e-mails/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    users = users[users['mail'].str.endswith('@leetcode.com')]
    users = users[~users['mail'].str.contains(r'[!#$%^&*()]')]
    users = users[~users['mail'].str.startswith('.')]
    users = users[users['mail'].str.match(r'^[a-zA-Z][\w.-]*@leetcode\.com$')]
    return users




