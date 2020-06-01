# Функция Гайзера-Хилласа


* [Wiki](https://en.wikipedia.org/wiki/Gaisser%E2%80%93Hillas_function) - страница в википедии

Функция Гайзера-Хилласа используется в астрофизике для параметризации продольного развития ШАЛ в атмосфере. 

$$N(x) = N_{max}\left(\frac{X-X_0}{X_[max]-X_0}\right)^{\frac{X_{max}-X_0}{\lambda}}\cdot \exp{\left(\frac{X_{max} - X}{\lambda} \right)}$$
где $$N_{max}$$ --- число частиц на максимуме $$X_{max}$$ развития  ливня. 
$$X_0, \lambda$$ - параметры которые зависят от энергии и массы первичной частицы. 

Если применить замену $$n=\frac{N}{N_{max}}, x=\frac{X-X_0}{\lambda}, m=\frac{X_{max}-X_0}{\lambda}$$, то мы можем вывести функцию Гайзера-Хилласа с одним параметром:

$$n(x) = \left(\frac{x}{m}\right)^{m}\cdot \exp{(m-x)}=\frac{x^m\cdot e^{-x}}{m^m\cdot e^{-m}}=\exp{\left(m(\ln{x}-\ln{m}) - (x - m)\right)}$$


