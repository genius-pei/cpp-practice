# cpp-practice — 手写数据结构 / C++ 模板 / Linux 进程练习

学习期按主题归拢的代码，不是玩具 demo：每一格都是当时真写过、跑过、调过 bug 的东西，合并自早期十来个零散练习仓库。

主线项目看 [journal-test](https://github.com/genius-pei/journal-test)（header-only 日志库）和 [oj-vibe_coding](https://github.com/genius-pei/oj-vibe_coding)（在线判题系统）。

## 目录

### `containers/` — C++ 模板版（`namespace yiming`，照 STL 接口写）

| 路径 | 内容 |
|---|---|
| `vector/` | `vector.h`：三指针迭代器、`reserve`/`resize`、`push_back` 扩容、拷贝与赋值 |
| `list/` | `List.h`：双向带头循环链表，迭代器封装 `->`  与 `++`/`--`、`insert`/`erase`、拷贝构造与析构 |
| `string/` | `String.h` + `String.cpp`（完整版）、`sim_string.cpp`（简化版）、`mystring.cpp`（另一版练习）：深拷贝、扩容、`operator=` / `[]` / 比较与拼接 |
| `stack-queue/` | `Stack.h`：容器适配器（默认 `std::vector` 底层，可换 `std::list`）；`priority_queue.h`：`Less`/`Greater` 比较器 + 堆调整 |
| `bst/` | `tree.h`：二叉搜索树插入 / 查找 / 删除（含左右子树都不空时的替换删除） |
| `avl/` | `AVLtree.h`：带平衡因子的 AVL，四种旋转（LL/RR/LR/RL） |
| `rb-tree/` | `BRTree.h` + `RBTree.h`：红黑树两版实现（插入修正、变色与旋转）；`mymap.h` / `myset.h` 在其上包出 map / set；`mapandset.cpp` 是接口比对 |
| `hash-table/` | 开放定址 + 状态标记删除（`EXIST`/`EMPTY`/`DELETE`）、仿 `std::hash` 的仿函数与 `string` 特化（BKDR）、在其上包出 `UnorderedMap` / `UnorderedSet`；`test.cpp` 用 100 万级数据对比 `std::set` / `std::unordered_set` 的插入与查找耗时 |

### `c-datastructures/` — C 版（.c/.h + 每章一个 main）

| 路径 | 内容 |
|---|---|
| `seqlist/` | 动态顺序表：增删查改、容量翻倍 |
| `single-list/` | 单链表：头插尾插、按值删除、逆置、找中间节点、判环 |
| `double-list/` | 双向链表 |
| `stack/` | 顺序栈 + 括号匹配、逆波兰等配套练习 |
| `queue/` | 链式队列 |
| `heap/` | 堆：向上/向下调整、建堆、`topk_test.c` 用堆取 TopK |
| `binary-tree/` | 链式二叉树：前中后序（递归 + 非递归）、层序、节点数/高度/叶子数 |
| `sort/` | 八大排序：插入、希尔、冒泡、选择、堆、快排（含 Lomuto 划分与非递归版）、归并、计数 |

### 其他

| 路径 | 内容 |
|---|---|
| `process/mini-shell/` | 迷你 shell：提示符拼装、读入行切分、`fork`+`exec` 执行外部命令、`wait` 回收，89 行 |
| `process/progress-bar/` | 终端进度条：`\r` 覆盖刷新、旋转光标、100% 边界与「已完成」状态机，由模拟下载循环驱动 |
| `process/fork-basics/` | `fork()` 返回值三路分支、`getpid` / `getppid` 观察父子关系 |
| `process/wait-and-exit/` | `fork` + `wait()` 回收子进程避免僵尸；`orphan-loop.c` 观察父进程先退后孤儿子进程被 init 接管 |
| `memory/` | RAII 智能指针雏形；`malloc/free` 与 `new/delete` 在构造析构、失败语义上的差异验证 |
| `c11/variadic-print.cpp` | 可变参数模板的递归展开：终止函数 + 参数包剥离 |
| `algorithm/sliding-window.cpp` | 滑动窗口题型练习（定长/不定长子数组） |
| `misc/` | 字符串原地反转、区间求和 |

## 编译

```bash
# 进程相关（Linux）
cd process/progress-bar && make && ./main
cd process/fork-basics && make && ./process      # ./myprocess 观察 pid/ppid

# 手写容器（头文件 + 各自的 test）
g++ -std=c++11 containers/list/List_test.cpp -o list && ./list
g++ -std=c++11 containers/avl/avl_test.cpp -o avl && ./avl
g++ -O2 containers/hash-table/test.cpp -o hashtest && ./hashtest

# C 数据结构（每个 .c 自带 main，逐个编）
gcc c-datastructures/sort/Sort_test.c c-datastructures/sort/Sort.c -o sort && ./sort
gcc c-datastructures/heap/heap_test.c c-datastructures/heap/heap.c -o heap && ./heap
```

头文件之间用相对路径引用（`#include "HashTable.h"`、`#include "RBTree.h"`），整个目录一起用即可。

## 说明

这些代码按当时的学习顺序写，命名风格不统一（`test.cpp`、`seqlistwork.c` 这类名字保留了原样），也没有统一构建——`*_test.*` 是同期的测试或作业，接口改过几版，不保证每个都能一次编过。

保留它们的原因是：能看出从「照教材敲」到「自己处理边界」的过程。比如 `progress-bar/process.c` 里的 `is_finished` 状态机，是第一版在 100% 处重复换行之后补的；`rb-tree` 里两版红黑树，第二版就是在第一版漏了兄弟节点为红的分支之后重写的。

MIT License。
