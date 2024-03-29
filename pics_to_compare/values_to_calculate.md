https://www.digitaldutch.com/atmoscalc/

https://cosmic.lbl.gov/SKliewer/Cosmic_Rays/Interaction.htm

# Определяемые величины
Надо иметь в виду, что генерировался 1 ливень с большим числом наблюдателей на разных высотах, а не несколько ливней по отдельности. Можно сгенерировать несколько ливней и взять среднее. 

## рис. 1, пространственное распределение
h = 12.2 км, задается в .list файле (и вероятно в reas файле). 
$$\Delta X_{max}$$ = -415 g/cm2.  - разница между глубиной наблюдения и глубиной максимума развития ливня. $$\Delta X=(X_{max} - X)$$
$$E_{rad}$$ = 3.2e+03 eV - находится интегрированием амплитуд (energy fluence) на антеннах.

Как найти energy fluence? 
$$f = f_{vxB}+f_{vxvxB}$$
$$f_{vxB} = \varepsilon_{0}\cdot c\cdot \Delta{t} \cdot E_{geo}^{2}$$
$$f_{vxvxB} = \varepsilon_{0}\cdot c\cdot \Delta{t} \cdot E_{ce}^{2}$$
$$f = \varepsilon_{0}\cdot c\cdot \Delta{t} \cdot (E_{geo}^{2}+E_{ce}^{2})$$
$$\varepsilon_{0}$$ - диэлектрическая проницаемость вакуума, $$\Delta{t}$$ - интервал выборки напряженности эл. поля E, c - скорость света в вакууме. $$E_{geo}$$ - напряженность электрического поля геомагнитной компоненты, $$E_{ce}$$ - напряженность электрического поля Аскарьяновской компоненты. 

Т.к. форма ФПР не линейна, а точную функцию мы не знаем, мы будем использовать метод трапеций. 
$$\int^{b}_{a}f(x)dx \approx h\cdot \left( \frac{f(x_{0})+f(x_{n}))}{2}+f(x_{1})+...f(x_{n-1})\right)$$
$$h=\frac{b-a}{n}$$
n - число шагов
$$f_{x_i}$$ - значение плотности на определенных точках. 
Для решения мы будем использовать n = 30 (число наблюдателей), f(x) для каждого n известно. 

## рис. 2 продольное распределение

Искомые значения:
* $$dE_{rad}/dX$$ - распределение E_rad на единицу X;
* Xmax - известно;
* Фит Гайзер-Хилласа
 
$$\frac{dE_{rad}}{dX}\left( \frac{X_{i}+X_{i+1}}{2}\right) = \frac{E_{rad}(X_{i+1})-E_{rad}(X_{i})}{X_{i+1}-X_{i}}$$

Фит по функции Гайсера-Хилласа осуществляется по следующей формуле:

$$\frac{dE_{rad}}{dX}(X) = A(\frac{X}{X^{rad}_{max}})^{\frac{X^{rad}_{max}}{\lambda}}\cdot exp(\frac{X^{rad}_{max}-X}{\lambda})$$

A, $$X^{rad}_{max}, \lambda$$ - являются свободными параметрами. 

