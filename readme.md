# Arduino Modbus-RTU 采集器
这是一个用Arduino实现的Modbus数据采集器，其工作模式为串口模式，主要用来外挂485设备
## 设计
<img src="./1.png">

## 构建
```sh
pio run -e esp12e -t upload --upload-port COM7
```
## 配置
- 串口速率：115200，无校验