# https://leetcode.com/problems/daily-leads-and-partners/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata




import pandas as pd

def daily_leads_and_partners(daily_sales: pd.DataFrame) -> pd.DataFrame:
    df_new = daily_sales.groupby(['date_id', 'make_name'])[['lead_id', 'partner_id']].nunique().reset_index()
    return df_new.rename(columns={'lead_id':'unique_leads', 'partner_id':'unique_partners'})




