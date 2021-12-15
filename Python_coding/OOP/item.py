import csv

class Item:
    pay_rate = 0.8
    all = []
    # указываем тип переменной в конструкторе
    # если есть переменная по умолчанию, то указывать не надо. переменная
    # по умолчанию показывает, что ожидается получить
    def __init__(self, name: str, price: float, quantity = 0):
        # validate values
        assert price >= 0, f"Price {price} is not greater than zero"
        assert quantity >= 0, f"Quantity {quantity} is not greater than zero"
        
        # Assign to self object
        self.__name = name # __ for private variable
        self.__price = price
        self.quantity = quantity
        
        # Actions to execute
        Item.all.append(self)
    
    @property
    # Property decorator = read-only decorator
    def name(self):
        return self.__name          

    @name.setter
    # allows to set a name
    def name(self, value):
        if len(value) > 10:
            raise Exception("The name is too long")
        else:
            self.__name = value

    @property
    # Property decorator = read-only decorator
    def price(self):
        return self.__price

    def apply_discount(self):
        self.__price = self.__price * self.pay_rate

    def apply_increment(self, increment_value):
        self.__price = self.__price + self.__price*increment_value
        
    @price.setter
    # allows to set a price
    def price(self, value)  :
        if price < 0:
            raise Exception("The price is below zero")
        else:
            self.__price = value

    # class method
    @classmethod
    def instantiate_from_csv(cls, filename):
        with open(filename, 'r') as f:
            reader = csv.DictReader(f)
            items = list(reader)
        
        # print read items
        for item in items:
            Item(
                name  = item.get('name'),
                price = float(item.get('price')),
                quantity = int(item.get('quantity'))
            )
    
    @staticmethod
    def is_integer(num):
        # we will count out floats that are point zero
        # i.e. 5.0, 10.0, 0.0 etc.
        if isinstance(num, float):
            # count out the floats that are point zero
            return num.is_integer()
        elif isinstance(num, int):
            return True
        else:
            return False
    
    def calculate_total_price(self):
        return self.__price * self.quantity;
    
    

    def __repr__(self):
        return f"{self.__class__.__name__}('{self.name}', {self.__price}, {self.quantity})"