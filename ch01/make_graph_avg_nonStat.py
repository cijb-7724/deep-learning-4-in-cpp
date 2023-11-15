import matplotlib.pyplot as plt

filename = 'avg_rates_nonStat.txt'
data = []

#データの読み込み
with open(filename) as file:
    for line in file:
        tmpList = [float(i) for i in line.split(' ')]
        data.append(tmpList)

plt.plot(range(0, len(data)), [r[0] for r in data], label='sample average')
plt.plot(range(0, len(data)), [r[1] for r in data], label='alpha const update')    


plt.xlabel('steps')
plt.ylabel('avg rate')
plt.legend()
plt.show()
