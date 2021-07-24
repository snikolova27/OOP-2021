# Абстрактни класове

## Задача 1
Създайте интерфейс (клас само с абстрактни методи) Vehicle. В него трябва да има следните методи:
- startMovement()
- stopMovement()

Създайте абстрактен клас Car наследваващ Vehicle. В него трябва да има следните полета и методи:
- double maxSpeed;
- double currentSpeed;
- double price;
- startEngine()
- stopEngine()
- accelerate()

Създайте класове SportCar и FamilyCar, които наследяват Car. Преценете кои методи трябва да се имплементират в Car и кои в наследниците.
Направете main, в който да демонстрирате, както полиморфизма, изграден от вас, така и работата на методите.

## Задача 2
Създайте клас Engine. В него трябва да има следните полета и методи:
- bool state (on/off)
- start()
- stop()
Добавете инстанция на Engine в Car. Направете извикване на методите и смяна на състоянието на state при викане на startEngine и stopEngine.

Направете main, в който да демонстрирате, работата на методите.