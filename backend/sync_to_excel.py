import pandas as pd
import datetime

# Simulated incoming data
scanned_items = [
    {"ItemID": "04a3f24d", "Name": "Milk", "Price": 45},
    {"ItemID": "0539ab88", "Name": "Bread", "Price": 25},
]

# Load or create Excel file
try:
    df = pd.read_excel("inventory.xlsx")
except FileNotFoundError:
    df = pd.DataFrame(columns=["ItemID", "Name", "Price", "Timestamp"])

# Add new items with timestamp
for item in scanned_items:
    item["Timestamp"] = datetime.datetime.now()
    df = pd.concat([df, pd.DataFrame([item])], ignore_index=True)

# Save back to Excel
df.to_excel("inventory.xlsx", index=False)
print("Excel database updated.")
