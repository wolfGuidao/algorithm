def main():
    list_a = [0 for i in range(10)]
    list_a[0] = 1
    print("list_a",list_a)
    for i in range(1, 10):
        print(i,end = ' ')

if __name__ == "__main__":
    main()
