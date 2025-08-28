1.创建weather类，在构造函数里起一个线程，以每隔1s调用measurementChanged方法。
并在调用该方法之前更新三个气象相关数据，简单的每个加0.01

2. 多个面板需要再有数据时被通知到。

2.1 weather类提供一个回调注册给到weatherObserver使用
2.2 weatherObserver提供所有对外面板接口
2.3 提供接口类，并且该类作为方法被回调间接调用到,weatherObserver存储该类作为register和unregister,
使用list来存储。
2.4 实际的面板实现该类。

3. weather和weatherObserver 两个类是什么关系?weatherObserver提供管理，weather提供底层业务驱动，
但是对外都是有weatherObserver提供管理，所以对外不需要暴露weather类。所有在weatherObserver类中创建
weather类
