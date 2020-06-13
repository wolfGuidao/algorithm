
def Func(money):
    woter = money
    no_woter_count = woter
    no_woter_count_sum = no_woter_count
    while no_woter_count:
        no_woter_count = no_woter_count_sum // 2
        woter += no_woter_count
        temp = no_woter_count_sum % 2
        no_woter_count_sum  =  no_woter_count + temp
    print(woter)

def main():
    Func(20)

if __name__ == "__main__":
    main()
