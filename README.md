# cpp-practice — C / C++ / Linux 练习集

学习期按主题归拢的代码，不是玩具 demo：每一格都是当时真写过、跑过、调过 bug 的东西，合并自早期十来个零散练习仓库（`314code`、`316code`、`317jincheng`、`LINUX`、`C11`、`Hash`、`Smart_pointer` 等）。

主线项目看 [journal-test](https://github.com/genius-pei/journal-test)（header-only 日志库）和 [oj-vibe_coding](https://github.com/genius-pei/oj-vibe_coding)（在线判题系统）。

## 目录

| 路径 | 内容 |
|---|---|
| `containers/hash-table/` | **手写哈希表**：开放定址 + 状态标记删除（`EXIST`/`EMPTY`/`DELETE`）、仿 `std::hash` 的仿函数并与 `string` 特化（BKDR）、在其上包出 `UnorderedMap` / `UnorderedSet`；`test.cpp` 用 100 万级数据对比 `std::set` / `std::unordered_set` 的插入与查找耗时 |
| `string/mystring.cpp` | 手写 string 类：迭代器（含 const 版本）、深拷贝、扩容、`operator=` / `[]` / 比较与拼接重载 |
| `process/progress-bar/` | 终端进度条：`\r` 覆盖刷新、旋转光标、100% 边界与「已完成」状态机，由模拟下载循环驱动；`fflush` 控制刷新时机 |
| `process/fork-basics/` | `fork()` 返回值三路分支、`getpid` / `getppid` 观察父子关系 |
| `process/wait-and-exit/` | `fork` + `wait()` 回收子进程避免僵尸；`orphan-loop.c` 用来观察父进程先退后孤儿子进程被 init 接管 |
| `c11/variadic-print.cpp` | 可变参数模板的递归展开：终止函数 + 参数包剥离 |
| `memory/smart-pointer.cpp` | RAII 智能指针雏形：构造接管、析构释放 |
| `memory/malloc-vs-new.cpp` | `malloc/free` 与 `new/delete` 在构造析构、失败语义上的差异验证 |
| `algorithm/sliding-window.cpp` | 滑动窗口题型练习（定长/不定长子数组） |
| `misc/` | 字符串原地反转、区间求和 |

## 编译

```bash
# 进程相关（Linux）
cd process/progress-bar && make && ./main
cd process/fork-basics && make && ./process      # ./myprocess 观察 pid/ppid

# 单文件
g++ -std=c++11 string/mystring.cpp -o mystring && ./mystring
g++ -O2 containers/hash-table/test.cpp -o hashtest && ./hashtest
```

`containers/hash-table` 只要 `#include "HashTable.h"`（或 `Unorderedmap.h` / `Unorderedset.h`），头文件之间用相对路径引用，整个目录一起用即可。

## 说明

这些代码按当时的学习顺序写，命名风格不统一（`test01.c`、`bench` 这类名字保留了原样），也没有统一构建。仓库里保留它们的原因是：能看出从「照教材敲」到「自己加边界处理」的过程——比如 `progress-bar/process.c` 里的 `is_finished` 状态机，就是第一版在 100% 处重复换行之后补的。

MIT License。
