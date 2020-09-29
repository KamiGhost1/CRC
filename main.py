import random


def init():
    """Initializing the input parameters"""
    gx = input("Enter the g(x): ")  # Generating polynomial
    gx = bin(int(gx, 2))
    epsilon = input(
        "Enter the epsilon: ")  # accuracy ε with which the program estimates the probability of decoding error
    l = input("Enter the l: ")  # The count of information transmitted symbols from messages m
    l = int(l)
    r = len(gx) - 3
    print(r)
    m = bin(l)  # Message
    return {'g(x)': gx, 'epsilon': epsilon, 'l': l, 'm': m, 'r': r, 'm(x)': None, 'a(x)': None, 'b(x)': None,
            'c(x)': None}


def xor(mx, gx):
    m, g = mx.split('b'), gx.split('b')
    m, g = m[1], g[1]
    c = list(m)
    for i in range(len(g)):
        if g[i] == "1" and m[i] == "1":
            c[i] = "0"

        if (g[i] == "1" and m[i] == "0") or (g[i] == "0" and m[i] == "1"):
            c[i] = "1"
    c = ''.join(c)
    c = c.split('0', 1)
    print(c, m, g)


def main():
    """Main program function"""
    coding_data = init()
    coding_data['m(x)'] = coding_data['m'] + '0' * coding_data['r']
    xor(coding_data['m(x)'], coding_data['g(x)'])
    print(coding_data)


if __name__ == "__main__":
    main()
