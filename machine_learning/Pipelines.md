# Pipelines
   
Pipelines are a simple way to keep your data preprocessing and modeling code organized. Specifically, a pipeline bundles preprocessing and modeling steps so you can use the whole bundle as if it were a single step.

Many data scientists hack together models without pipelines, but pipelines have some important benefits. Those include:

* **Cleaner Code:** Accounting for data at each step of preprocessing can get messy. With a pipeline, you won't need to manually keep track of your training and validation data at each step.
* **Fewer Bugs**: There are fewer opportunities to misapply a step or forget a preprocessing step.
* **Easier to Productionize**: It can be surprisingly hard to transition a model from a prototype to something deployable at scale. We won't go into the many related concerns here, but pipelines can help.

# Examples

# Step 1: Define Preprocessing Steps
```
# this library allows us to transform columns of our data
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
# simple imputer allows us to deal with missing data. Both numerical and categorical
from sklearn.impute import SimpleImputer
# onehotencoder is another library to deal with missing data, categorical in this case
from sklearn.preprocessing import OneHotEncoder

# let's create our transformers for both numerical and categorical datatypes
# Preprocessing for numerical data. strategy = constants means that we fill missing data with constant value
numerical_transformer = SimpleImputer(strategy='constant')

# Preprocessing for categorical data. We are going to two types of categorical transformers. Simple imputer for missing data and one hot encoder to deal with categorical data.
# On general models can't work with categorical data so we have to transform it to numerical data, so our model can train on them
categorical_transformer = Pipeline(steps=[
    ('imputer', SimpleImputer(strategy='most_frequent')),
    ('onehot', OneHotEncoder(handle_unknown='ignore'))
])

# Bundle preprocessing for numerical and categorical data
preprocessor = ColumnTransformer(
    transformers=[
        ('num', numerical_transformer, numerical_cols),
        ('cat', categorical_transformer, categorical_cols)
    ])
```

# Step 2: Define the Model
```
from sklearn.ensemble import RandomForestRegressor

# instantiate our model. n_estimators = 100 was optimal for the data this example is using. For different data that value would be different.
model = RandomForestRegressor(n_estimators=100, random_state=0)
```

# Step 3: Create and Evaluate the Pipeline
```
from sklearn.metrics import mean_absolute_error

# Bundle preprocessing and modeling code in a pipeline
my_pipeline = Pipeline(steps=[('preprocessor', preprocessor),
                              ('model', model)
                             ])

# By one line code we first preprocess data by preprocessor, then fit with our model 
my_pipeline.fit(X_train, y_train)

# Preprocessing of validation data, get predictions
preds = my_pipeline.predict(X_valid)

# Evaluate the model
score = mean_absolute_error(y_valid, preds)
print('MAE:', score)


```

# Advanced Pipeline
вроде пон€л, у мен€ сам XGBoost не хочет работать с моими данными почему то. Ќадо бы посмотреть, как XGBoost использовалс€ дл€ моих данных с 
самого начала а потом использовать дл€ pipeline'ов

„е то не получаетс€ с pipeline, видимо препроцессор не работает почему то. Ќадо заново посмотреть как работает препроцессор. XGBoost €
заставил работать, но без пайплайна

читал про onehotencoder и чем он отличаетс€ от pandas.get_dummies. 
onehotencoder позвол€ет разделить разные базы данных одинаково, в отличие от get_dummies. 
  примеру если у нас есть X_train и X_test. ” X_train есть колонка со цветами, скажем красный, зеленый и синий. ј у X_test нету синего,
то при использовании get_dummies может возникнуть ошибка в разном количестве колонок. “огда, как onehotencoder разделит колонку
правильно. 

реализован onehotencoder и simpleimputer.
Ќадо теперь реализовать xgbregressor

