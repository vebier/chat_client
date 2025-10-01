#ifndef GLOBAL_H
#define GLOBAL_H
#include <functional>
#include <QWidget>
#include <QStyle>
#include <memory>
#include <mutex>
#include <QDebug>
#include <QDir>
#include <QSettings>
#include <QFile>
#include <string>
#include <cctype>
#include <unordered_set>

extern std::function<void(QWidget*)> repolish;

extern QString gate_url_prefix;

enum class ReqId{
    ID_GET_VARIFY_CODE = 1001,  //获取验证码
    ID_REG_USER = 1002,         //注册用户
};

enum class ErrorCodes{
    SUCCESS = 0,
    Error_Json = 1001,  //Json解析错误
    RPCFailed = 1002,  //RPC请求错误
    VarifyExpired = 1003, //验证码过期
    VarifyCodeErr = 1004, //验证码错误
    UserExist = 1005,       //用户已经存在
    PasswdErr = 1006,    //密码错误
    EmailNotMatch = 1007,  //邮箱不匹配
    PasswdUpFailed = 1008,  //更新密码失败
    PasswdInvalid = 1009,   //密码更新失败
    TokenInvalid = 1010,   //Token失效
    UidInvalid = 1011,  //uid无效
    ERR_NETWORK = 1012,
};

enum class Modules{
    REGISTERMOD = 0,    //注册模块
};

// 密码验证结果结构
struct PasswordResult {
    bool valid;
    std::string message;

    PasswordResult(bool v, const std::string& m) : valid(v), message(m) {}
};

#endif // GLOBAL_H
