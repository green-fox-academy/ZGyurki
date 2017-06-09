def is_binary(input_str):
    length = len(input_str)
    for i in range(0, length):
        if int(input_str[i]) > 1:
            return False
    return True


def change_to_decimal(input_str):
    length = len(input_str)
    new_length = length - 1
    add = 0
    for i in range(0, length):
        add += (int(input_str[i])*(2**new_length))
        new_length -= 1
    print(add)


def change_from_hexad(input_str):
    length = len(input_str)
    new_length = length - 1
    add = 0
    for i in range(0, length):
        if input_str[i] == 'A':
            add += (10*(16**new_length))
            new_length -= 1
        elif input_str[i] == 'B':
            add += (11*(16**new_length))
            new_length -= 1
        elif input_str[i] == 'C':
            add += (12*(16**new_length))
            new_length -= 1
        elif input_str[i] == 'D':
            add += (13*(16**new_length))
            new_length -= 1
        elif input_str[i] == 'E':
            add += (14*(16**new_length))
            new_length -= 1
        elif input_str[i] == 'F':
            add += (15*(16**new_length))
            new_length -= 1
        else:
            add += (int(input_str[i])*(16**new_length))
            new_length -= 1
    print(add)


def main_binary():
    while True:
        some_string = input('\nKérlek, adj meg egy számot, amit vizsgáljak: ')
        binary = is_binary(some_string)
        if binary == False:
            print('Ez nem bináris szám.\n')
        else:
            print('Találat!')
            decimal = change_to_decimal(some_string)


def main_hexad():
    while True:
        some_string = input('\nKérlek, adj meg egy számot, amit vizsgáljak: ')
        decimal = change_from_hexad(some_string)


def abs_main():
    choice = input('Miben szeretnél dolgozni? \nHa binárisban, írd be: BIN, ha hexadecimálisban, írd be: HEX \n')
    if choice == 'BIN':
        BIN = main_binary()
    elif choice == 'HEX':
        HEX = main_hexad()

abs_main()