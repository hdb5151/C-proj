# 时间相关表

<table border=1>
  <td>类型/命名空间</td>
  <td>函数</td>
  <td>返回值</td>
<tr>
  <td rowspan=2> std::this_thread[namespace] </td>
  <td> sleep_for(duration) </td>
  <td rowspan=2>N/A</td>
</tr>
<tr>
  <td>sleep_until(time_point)</td>
</tr>
<tr>
  <td rowspan = 4>std::condition_variable 或 std::condition_variable_any</td>
  <td>wait_for(lock, duration)</td>
  <td rowspan = 2>std::cv_status::time_out 或 std::cv_status::no_timeout</td>
</tr>
<tr>
  <td>wait_until(lock, time_point)</td>
</tr>
<tr>
  <td> wait_for(lock, duration, predicate)</td>
  <td rowspan = 2>bool —— 当唤醒时，返回谓词的结果</td>
</tr>
<tr>
  <td>wait_until(lock, duration, predicate)</td>
</tr>
<tr>
  <td rowspan = 2>std::timed_mutex 或 std::recursive_timed_mutex</td>
  <td>try_lock_for(duration)</td>
  <td rowspan = 2> bool —— 获取锁时返回true，否则返回fasle</td>
</tr>
<tr>
  <td>try_lock_until(time_point)</td>
</tr>
<tr>
  <td rowspan = 4>std::unique_lock&lt;TimedLockable&gt;</td>
  <td>unique_lock(lockable, duration)</td>
  <td>N/A —— 对新构建的对象调用owns_lock();</td>
</tr>
<tr>
  <td>unique_lock(lockable, time_point)</td>
  <td>当获取锁时返回true，否则返回false</td>
</tr>
<tr>
  <td>try_lock_for(duration)</td>
  <td rowspan = 2>bool —— 当获取锁时返回true，否则返回false</td>
</tr>
<tr>
  <td>try_lock_until(time_point)</td>
</tr>
<tr>
  <td rowspan = 3>std::future&lt;ValueType&gt;或std::shared_future&lt;ValueType&gt;</td>
  <td>wait_for(duration)</td>
  <td>当等待超时，返回std::future_status::timeout</td>
</tr>
<tr>
  <td rowspan = 2>wait_until(time_point)</td>
  <td>当“期望”准备就绪时，返回std::future_status::ready</td>
</tr>
<tr>
  <td>当“期望”持有一个为启动的延迟函数，返回std::future_status::deferred</td>
</tr>
</table>

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

# 创建类
>* 包含 #include<thread>
>* 方法 std::thread mythread(function,parm,...)
# ------------------------------------------------------------------------------------------------------------------------------------------------------------

# 互斥量
## 互斥量类型
<table border=1>
  <td>类模板</td><td>描述</td>
<tr>
  <td>std::mutex</td> <td>同一时间只可被一个线程锁定。如果它被锁住，任何其他lock()都会阻塞(block)，直到这个<br/>mutex再次可用，且try_lock()会失败。</td>
</tr>
<tr>
  <td>std::recursive_mutex</td> <td>允许在同一时间多次被同一线程获得其lock。其典型应用是：函数捕获一个lock并调用另一函数<br/>而后者再次捕获相同的lock。</td>
</tr>
<tr>
  <td>std::timed_mutex</td> <td>额外允许你传递一个时间段或时间点，用来定义多长时间内它可以尝试捕获一个lock。为此它提<br/>供了try_lock_for(duration)和try_lock_until(timepoint)。</td>
</tr>
<tr>
  <td>std::recursive_timed_mutex</td> <td>允许同一线程多次取得其lock，且可指定期限。</td>
</tr>
</table>

## 不同互斥类所支持的互斥锁类型
<table border=1>
  <td>操作/operator</td><td>mutex</td><td>recursive_mutex</td><td>timed_mutex</td><td>recursive_timed_mutex</td>
<tr>
  <td>lock()</td><td colspan="4" align="center">捕获mutex(若无捕获则堵塞)</td>
</tr>
<tr>
  <td>try_lock()</td><td colspan="4" align="center">捕获mutex(若无捕获则返回false)</td>
</tr>
<tr>
  <td>try_lock()</td><td colspan="4" align="center">解除被锁定的mutex</td>
</tr>
<tr>
  <td>try_lock_for()</td><td align="center">----</td><td align="center">----</td><td colspan="2" align="center">试着在时间段内捕获一个lock</td>
</tr>
<tr>
  <td>try_lock_for()</td><td align="center">----</td><td align="center">----</td><td colspan="2" align="center">试着捕获一个lock直到某个时间点</td>
</tr>
<tr>

</tr>
</table>

# 锁 lock_guard与unique_lock

<table border=1>
  <td>锁类型</td><td>描述</td>
<tr>
  <td>std::lock_guard</td><td>严格基于作用域(scope-based)的锁管理类模板，构造时是否加锁是可选的(不加锁时假定当前线程已经获得<br/>锁的所有权—使用std::adopt_lock策略)，析构时自动释放锁，所有权不可转移，对象生存期内不允许手动<br/>加锁和释放锁</td>
</tr>
<tr>
  <td>>std::unique_lock</td><td>更加灵活的锁管理类模板，构造时是否加锁是可选的，在对象析构时如果持有锁会自动释放锁，所有权可以<br/>转移。对象生命期内允许手动加锁和释放锁</td>
</tr>
</table>

>* 定义互斥量 ***m***
>>* std::mutex m;
>>* std::recursive_mutex m;
>>* std::timed_mutex m;
>>* std::recursive_timed_mutex m;
## lock_guard
>* 定义锁 ***lo***
>>* std::lock_guard<T> lo(T)
<table border=1>
  <td>操作函数</td><td>描述</td>
<tr>
  <td>lock_guard lg(m)</td><td>为互斥量m建立一个lock_guard并锁定之</td>
</tr>
<tr>
  <td>lock_guard lg(m,adopt_lock)</td><td>为已经被锁定的互斥量m建立一个lock_guard,adopt_lock为已上锁标识</td>
</tr>
</table>

## unique_lock
### 构造函数

<table border=1>
    <td>操作函数</td><td>描述</td>
<tr>
  <td>unique_lock locker</td><td>默认构造函数,建立一个lock,但不关联任何mutex</td>
</tr>
<tr>
  <td>unique_lock locker(m)</td><td>为互斥量建立一个unique_lock,并锁定它</td>
</tr>
<tr>
  <td>unique_lock locker(m,adopt_lock)</td><td>为已锁定的互斥量建立一个unique_lock</td>
</tr>
<tr>
  <td>unique_lock locker(m,defer_lock)</td><td>为互斥量建立一个unique_lock,但是暂时不锁定它,配置unique_lock成员函数完成锁定任务</td>
</tr>
<tr>
  <td>unique_lock locker(m,try_to_lock)</td><td>为互斥量建立一个unique_lock,并尝试锁定它,无论锁定与否,都不堵塞.可以通过locker.owns_lock()<br/>或locker是否==true查看是否锁定</td>
</tr>
<tr>
  <td>unique_lock locker(m,duraing)</td><td>为互斥量建立一个unique_lock,并尝试在时间段duraing锁定它</td>
</tr>
<tr>
  <td>unique_lock locker(m,timepoint)</td><td>为互斥量建立一个unique_lock,并尝试在时间点timepoint之前锁定它</td>
</tr>
<tr>
  <td>unique_lock locker(relocker)</td><td>Move构造函数,将所有权从relocker转移到locker,从此relocker不再关联互斥量m</td>
</tr>
<tr>
  <td>unique_lock locker=relocker</td><td>Move构造函数,将所有权从relocker转移到locker,从此relocker不再关联互斥量m</td>
</tr>
</table>

### unique_lock 成员函数

<table border=1>
  <td>操作函数</td><td>描述</td>
<tr>
  <td>swap(locker1,locker2)</td><td>交互unique_lock所有权</td>
</tr>
<tr>
  <td>locker1.swap(locker2)</td><td>交互unique_lock所有权</td>
</tr>
<tr>
  <td>locker.release()</td><td>返回一直指针,指向被释放的互斥量,并将该互斥量释放</td>
</tr>
<tr>
  <td>locker.owns_lock()</td><td>如果关联的mutex被锁定则返回true</td>
</tr>
<tr>
  <td>if(locker)</td><td>如果l关联的互斥量被锁定,则返回true</td>
</tr>
<tr>
  <td>locker.mutex()</td><td>返回一个指向关联互斥量的指针</td>
</tr>
<tr>
  <td>locker.lock()</td><td>锁住关联的互斥量</td>
</tr>
<tr>
  <td>locker.try_lock()</td><td>尝试锁住关联的互斥量,如果成功则返回true</td>
</tr>
<tr>
  <td>locker.try_lock_for(duraing)</td><td>尝试在时间段duraing内锁住关联的互斥量,如果成功则返回true</td>
</tr>
<tr>
  <td>locker.try_lock_until(timepoint)</td><td>尝试在到达时间点timepoint之前锁住关联的互斥量,如果成功则返回true</td>
</tr>
<tr>
  <td>locker.unlock()</td><td>解除关联的互斥量</td>
</tr>
</table>

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

# 条件变量 <conditon_cariable>
>* 原则上条件变量运行如下:
>>* 必须同时包含< mutex >和< condition_variable >，并声明一个mutex和一个condition_variable变量；
>>* 那个通知“条件已满足”的线程（或多个线程之一）必须调用notify_one()或notify_all()，以便条件满足时唤醒处于等待中的一个条件变量；
>>* 那个等待"条件被满足"的线程必须调用wait()，可以让线程在条件未被满足时陷入休眠状态，当接收到通知时被唤醒去处理相应的任务；

## 声明:
>>* std::condition_variable cv;
 

## 成员列表

<table border=1>
  <td>函数</td><td>描述</td>
<tr>
  <td>cv.notify_one()</td><td>唤醒一个等待者(线程)</td>
</tr>
<tr>
  <td>cv.notify_all()</td><td>唤醒所有等待者(线程)</td>
</tr>
<tr>
  <td>cv.wait(unlock)</td><td>使用unique_lock unlock来等待通知</td>
</tr>
<tr>
  <td>cv.wait(unlock,pred)</td><td>使用unique_lock unlock来等待通知,如果pred==true则直接返回,如果pred==false则堵<br/>塞线程,直到收到通知后再继续执行,pred可以使用lambda表示[](){return false}</td>
</tr>
<tr>
  <td>cv.wait_for(unlock,duraing)</td><td>使用unique_lock unlock来等待通知,如果在时间段duraing内收到通知则返回ture,并再继续执行下面代码{return false}</td>
</tr>
<tr>
  <td>cv.wait_for(unlock,duraing,pred)</td><td>使用unique_lock unlock来等待通知,如果pred==true则直接返回,如果pred==false则堵<br/>塞线程,如果在时间段duraing内收到通知则返回ture,并再继续执行下面代码,pred可以<br/>使用lambda表示[](){return false}</td>
</tr>
<tr>
  <td>cv.wait_until(unlock,timepoint)</td><td>使用unique_lock unlock来等待通知,如果在时间点timepoint到达前收到通知则返回ture,并再继续执行下面代码</td>
</tr>
<tr>
  <td>cv.wait_until(unlock,timepoint,pred)</td><td>使用unique_lock unlock来等待通知,如果pred==true则直接返回,如果pred==false则堵<br/>塞线程,如果在时间点timepoint到达前收到通知则返回ture,并再继续执行下面代码,<br/>pred可以使用lambda表示[](){return false}</td>
</tr>
<tr>
  <td>notify_all_at_thread_exit(cv,unlock)</td><td>在线程退出时唤醒所有等待者(线程)</td>
</tr>
</table>

## 注意点
>* 所有等待某个条件变量(condition variable)的线程都必须使用相同的mutex，当wait()家族的某个成员被调用时该mutex必须被unique_lock锁定，否则会发生不明确的行为；
>* wait()函数会执行“解锁互斥量–>陷入休眠等待–>被通知唤醒–>再次锁定互斥量–>检查条件判断式是否为真”几个步骤，这意味着传给wait函数的判断式总是在锁定情况下被调用的，可以安全的处理受互斥量保护的对象；但在"解锁互斥量–>陷入休眠等待"过程之间产生的通知(notification)会被遗失。