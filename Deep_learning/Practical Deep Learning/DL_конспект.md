The State of Deep Learning


### Vision
* Detection; Classification

### Test
* Classification; Conversation
Deep Learning не хочень хорош в Conversation, он хорош для того, чтобы дать точный ответ или ответ, который похож на точный. Но на задавание вопросов, ответу на нестандартные вопросы, испытвает определенные трудности. Эта была одна из больших разочарований для частных компаний, которые надеялись использовать эту систему вместо своих сотрудников в качестве чат-ботов, операционистов и т.п.


### Tabular
* High Cardinality; GPU (Rapids)
Deep Learning не очень хорош для этих вещей. Есть более совершенные, быстрые и удобные техники для этих целей

### Recsys (рекоммендательная система)
* Prediction <> Recommendation
Deep Learning очень хорош для прдесказаний, но т.к. рекоммендации это не предсказания, он испытывает трудности в этом плане.

### Multi-modal
* Labeling; Captioning; Human in the loop
В этой сфере у Deep Learning нет соперников. multi-modal имеется в виду сильно разновидные данные: где у нас есть и текстовые данные, и табличные данные, и рисунки и т.п. deep learning очень хорошо систематизирует их и способен классифицировать их, давать предсказания, анализировать, и т.п.
Captioning --- это когда модель автоматически добавляет подписи к рисункам и фотографиям. Правда при этом возможны ошибки и весьма существенные (пр. если на фото 3 птицы, то модель может написать, что на фото 2 птицы).

### Other
* NLP .> Protein

p-value is used to find a relationship between values
Для начала мы берем т.н. "null hypothesis"
- начальная гипотеза. Она может утверждать что-либо, например, что нету никакой связи между двумя параметрами.

- собираем данные независимых данных и зависимых данных. Например температура и R - трансмиссивность болезни.

- в скольки процентах случаев мы будем наблюдать такую связь случайно?

```
1) Генерируем случайные данные: скажем
температура(C): mean 5 Std 5
R: mean 1.9 Std 0.5

2) Повторить <n> раз

3) рассчитать процент
(#slope < - 0.023)/ <n>
```


### Datablock API
```
bears = Datablock(
    blocks=(ImageBlock, CategoryBlock),
    get_items=get_image_files,
    splitter=RandomSplitter(valid_pct=0.3,seed=42),
    get_y=parent_label,
    item_tfms=Resize(128)
  )
```
в blocks:
ImageBlock --- независимая переменная (input data)
CategoryBlock --- зависимая переменная (labels)

в get_items: (как получить список имен файлов). Надо передать название функции, которая будет использоваться для этой задачи.

splitter --- как будем разделять данные.

get_y --- названия категорий данных (label names), здесь используется функция parent_label, которая берет название родительской папки. Это самый распространенный способ хранения и организации данных в data vision.

items_tfms --- items transform, трансформация данных, в данном случае рисунка.
была использована функция Resize (128), т.е. 128х128

**Алгоритм работы функции DataBlock**.
1. get_items --- используется get_image_files
2. get_x, get_y (getters) --- в данном примере у нас только get_y
3. blocks[0].create, block[1].create --- создается ImageBlock и CategoryBlock
4. item_tfms --- трансформируем наши рисунки
5. Collate(DataLoader) --- DataLoader создает batch (по умолч. 64), это определенное число рисунков сшитых вместе, которые затем расчитываются видеокартой. Использование таких batch позволяет ускорить время обучения. DataLoades includes validation and training. A dataloader is a class which provides *batches* of a few items at a time to the GPU. We'll be learning a lot more about this class in the next chapter. When you loop through a DataLoader fastai will give you 64 (by default) items at a time, all stacked up into a single tensor. We can take a look at a few of those items by calling the show_batch method on a DataLoader
6. batch_tfms

В fastai есть уже готовая функция экспорта. Эта функция используется для того, чтобы можно было использовать обученную модель онлайн, в приложениях или где-то удаленно.
Функция заключается в том, чтобы сохранить все веса (параметры) и архитектуру модели.
В tensorflow тоже была такая функция.
