#pragma once

/**
* 被任何一个模块包含都会产生不同的实体，所谓的模块就是".h, .cpp"的组合体
*/
static int staticInCommDefine = 100;

/**
* 非static就不能在这里定义了，被多个文件包含时会出现重复定义的编译错误
*/
extern int inCommDefine;