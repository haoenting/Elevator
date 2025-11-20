嚮樂科技面試測驗
1. main.cpp :
    - 檢查輸入是否合法
    - 輸入要放到 up 還是 down queue
2. Controller :
    - 將request進行排序
        - up : start小的在前，end大的在後
        - down : start大的在前，end小的在後
    - 檢查電梯往上還下
3. Elevator :
    - 看mission.empty()
    - if空，找相同方向的queue是否有東西
        - 有request，更新mission
        - 沒有，停在原地等or改變方向
    - if 沒空，繼續mission

