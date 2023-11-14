import matplotlib.pyplot as plt

filename = 'avg_rates.txt'
data = []

#データの読み込み
with open(filename) as file:
    for line in file:
        data.append(float(line))


plt.plot(range(0, len(data)), data, label='avg rate')    
plt.xlabel('steps')
plt.ylabel('avg rate')
plt.legend()
plt.show()
