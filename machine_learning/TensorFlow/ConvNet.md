# Convolutional Network

 **Zero padding of the image** --- этот прием используется для того, чтобы оставить размер рисунка неизменным. К примеру, если у нас размер рисунка 7х7 и мы используем филтр 3х3, то в результате мы получим 5х5 рисунок, после фильтра. Если добавить дополнительный столбец и строку со значениями 0, то после фильтра получится рисунок 7х7. Есть простое правило, как подобрать размер паддинга:
 (F-1)/2, где F --- это размер фильтра FxF. 
 
 Рассмотрим пример, дан рисунок 32х32х3 и мы используем 10 фильтров 5х5х3 и паддинг 2. После обработки мы получим рисунок 32х32х10 --- **глубина равна количество фильтров**. Количество параметров в данной случаем будет равно (5*5*3 + 1) * 10 = 760. Число параметров равно (H*W*D + 1) * N_layers. единичка - это значение bias --- $$w_0$$
 
 Надо иметь в виду, что часто вместо "фильтра" используют слово "kernel", поэтому не надо путаться. просто держите это в голове. 

 Существует несколько моделей, которые выигрывали соревнование ImageNet, такие как AlexNet, VGGNet, GoogLeNet и ResNet. Каждый год, точность победителя повышалась, но при этом увеличивалось количество слоев. Чем больше слоев, тем больше вычислений надо делать, но при этом уменьшается нагрузка на оперативную память, т.к. используется меньше параметров. Результаты этих моделей можно резюмировать следующим:
 
 1) Используйте Average Pooling, чтобы уменьшить число параметров, перед FC, вместо Max Pooling;
 2) VGGNet и GoogLeNet по результату почти равны, но VGGNet использует ConvNet, а GoogLeNet Inception Net, что неоправданно усложняет читаемость модели;
 3) Чем больше слоев, тем выше точность с оговоркой. Надо добавлять слои так же как ResNet.
 
 Resnet (152 слоя) получил точность 3.6% на топ 5. Обучался 2-3 недели на 8 GPU. Однако при этом работал быстрее VGGNet (19 слоев).
 