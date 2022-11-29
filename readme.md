# о программе 
данная программа предназначена для моделирования и оценки вероятности ошибки декодирования при передаче данных по ДСК

# подготовка перед запуском
- для начала убедитесь что у вас установлен компилятор 
```
sudo apt install g++
```
- убедитесь что у вас установлен gnuplot
```
sudo apt install gnuplot
```
- соберите программу 
```
g++ *.cpp -o exec
```

- или соберите пребилд при помощи cmake

```
cmake .
```
- или соберите программу при помощи make
```
make
```

# перед началом
- создайте папку "graphs"
```
mkdir graphs
```

# старт 
- чтобы смоделировать все возможные вероятности для каждой длинны сообщения(до 10 бит информации)
```
./exec --start
```
- чтобы смоделировать все возможные вероятности для определенной длины сообщения
```
./exec --start --once
```
- чтобы смоделировать определенную вероятность для определенной длины сообщения
```
./exec --start --only_once
```

## режим модернизированной модели ошибки только в 1.

- чтобы смоделировать все возможные вероятности для каждой длинны сообщения(до 10 бит информации)
```
./exec --start -m
```
- чтобы смоделировать все возможные вероятности для определенной длины сообщения
```
./exec --start --once -m
```
- чтобы смоделировать определенную вероятность для определенной длины сообщения
```
./exec --start --only_once -m
```

## доп функции 

- чтобы вывести все кодовые слова 
```
./exec --words
```

- чтобы вывести среднеквадратичное отклонение
```
./exec -i <path> -c <path>
```

## тестовые функции 

- деленние "уголком"
```
./exec --div
```
- бинарный вид 
```
./exec --bin
```
- генератор ошибки 
```
./exec --err
```
- генератор случайного числа 
```
./exec --test
```
- размер сообщения в битах 
```
./exec --msg
```