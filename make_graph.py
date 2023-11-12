import matplotlib.pyplot as plt

#mode 1:total reward, 2:rate
mode = 2

if mode == 1:
    filename = 'total_rewards.txt'
else:
    filename = 'rates.txt'
data = []

#データの読み込み
with open(filename) as file:
    for line in file:
        data.append(float(line))


if mode == 1:
    plt.plot(range(0, len(data)), data, label='total reward')
else:
    plt.plot(range(0, len(data)), data, label='rate')
    
plt.xlabel('steps')

if mode == 1:
    plt.ylabel('total reward')
else:
    plt.ylabel('rate')


plt.legend()
plt.show()
