import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

df = pd.read_csv("ndpoints.txt", header=None)
df.columns = ["x", "y"]
sns.scatterplot(x=df["x"], 
                y=df["y"])
plt.title("Scatterplot of (y) vs  (x)")
plt.show()