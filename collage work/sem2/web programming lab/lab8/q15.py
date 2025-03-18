# 15. Get top three items in a shop
shop_data = {'item1': 45.50, 'item2': 35, 'item3': 41.30, 'item4': 55, 'item5': 24}
top_items = sorted(shop_data.items(), key=lambda x: x[1], reverse=True)[:3]
print(top_items)