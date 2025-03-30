import time

class ThreeStates:
    def __init__(self):
        self.__state = None
    
    def hasstate(self):
        self.__state = "1 состояние"
        print(self.__state)
        time.sleep(5)
        
        self.__state = "2 состояние"
        print(self.__state)
        time.sleep(3)
        
        self.__state = "3 состояние"
        print(self.__state)
        time.sleep(2)
        
        print("переключение завершено")

print("- - тестирование ThreeStates - -")
three_states_instance = ThreeStates()
three_states_instance.hasstate()
print("\n")


class Volume:
    def __init__(self, length, width, height):
        self._length = length
        self._width = width
        self._height = height
    
    def calculate_volume(self):
        volume = self._length * self._width * self._height
        return volume

print("- - тестирование Volume - -")
volume_instance = Volume(3, 4, 5)
print("объем:", volume_instance.calculate_volume())
print("\n")


class Employee:
    def __init__(self, name, patronymic, surname, wage, bonus):
        self.name = name
        self.patronymic = patronymic
        self.surname = surname
        self._salary = {"плата": wage, "бонус": bonus}


class Salary(Employee):
    def get_full_name(self):
        return f"{self.surname} {self.name} {self.patronymic}"
    
    def get_total_income(self):
        return self._salary["плата"] + self._salary["бонус"]

print("- - тестирование Salary - -")
employee_salary = Salary("Иван", "Иванович", "Петров", 50000, 10000)
print("полное имя:", employee_salary.get_full_name())
print("общий доход:", employee_salary.get_total_income())
print("\n")


class Airplane:
    def __init__(self, speed, color, name, is_jet):
        self.speed = speed
        self.color = color
        self.name = name
        self.is_jet = is_jet
    
    def go(self):
        print(f"{self.name} взлетает")
    
    def stop(self):
        print(f"{self.name} садится")
    
    def direction(self, direction):
        print(f"{self.name} повернул {direction}.")
    
    def show_speed(self):
        print(f"текущая скорость {self.name}: {self.speed} км/ч")


class FastAirplane(Airplane):
    def show_speed(self):
        if self.speed > 1300:
            print(f"{self.name}: скорость сверхзвуковая")
        else:
            print(f"{self.name}: скорость в пределах нормы ({self.speed} км/ч)")


class Biplane(Airplane):
    pass


class ArmyAirplane(Airplane):
    pass

print("- - Тестирование Airplane и дочерних классов - -")
plane1 = Airplane(800, "Белый", "самолет", False)
fast_plane = FastAirplane(1400, "Серый", "скоростной самолет", True)
biplane = Biplane(300, "Красный", "биплан", False)
army_plane = ArmyAirplane(900, "Зеленый", "армейский самолет", True)

plane1.go()
plane1.show_speed()
plane1.direction("налево")
plane1.stop()
print()

fast_plane.go()
fast_plane.show_speed()
fast_plane.direction("направо")
fast_plane.stop()
print()

biplane.go()
biplane.show_speed()
biplane.direction("вверх")
biplane.stop()
print()

army_plane.go()
army_plane.show_speed()
army_plane.direction("назад")
army_plane.stop()
print("\n")


class MathOperations:
    def __init__(self, first_num, second_num):
        self.first_num = first_num
        self.second_num = second_num
    
    def calc(self):
        print("запуск операции")


class my_sum(MathOperations):
    def calc(self):
        print("запуск операции сложения")
        result = self.first_num + self.second_num
        print(f"сумма: {result}")
        return result


class my_sub(MathOperations):
    def calc(self):
        print("запуск операции вычитания")
        result = self.first_num - self.second_num
        print(f"разность: {result}")
        return result


class my_mult(MathOperations):
    def calc(self):
        print("запуск операции умножения=")
        result = self.first_num * self.second_num
        print(f"произведение: {result}")
        return result

print("- - тестирование MathOperations - -")
sum_instance = my_sum(10, 5)
sub_instance = my_sub(10, 5)
mult_instance = my_mult(10, 5)

sum_instance.calc()
sub_instance.calc()
mult_instance.calc()
