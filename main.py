import random


def init():
    """Initializing the input parameters"""
    g_x = input("Enter the g(x): ")  # Generating polynomial
    g_x = bin(int(g_x, 2))
    epsilon = input(
        "Enter the epsilon: ")  # accuracy ε with which the program estimates the probability of decoding error
    l = input("Enter the l: ")  # The count of information transmitted symbols from messages m
    l = int(l)
    r = len(g_x) - 2
    print(r)
    k = random.randint(5, 100)  # Message length
    m = bin(random.getrandbits(k))  # Message
    return {'g(x)': g_x, 'epsilon': epsilon, 'l': l, 'k': k, 'm': m, 'r': r}


def main():
    """Main program function"""
    coding_data = init()
    print(coding_data)


if __name__ == "__main__":
    main()
