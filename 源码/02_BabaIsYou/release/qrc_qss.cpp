/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.9.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // C:/Enfile/qt_documents/02_BabaIsYou/testQss.qss
  
  
  
static const unsigned char qt_resource_data[872] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // testQss.qss
  0x0,0xb,
  0x8,0x53,0xcd,0x83,
  0x0,0x74,
  0x0,0x65,0x0,0x73,0x0,0x74,0x0,0x51,0x0,0x73,0x0,0x73,0x0,0x2e,0x0,0x71,0x0,0x73,0x0,0x73,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/testQss.qss
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x8a,0xa5,0xec,0x87,0x5f,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_qss)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_qss)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qss)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qss)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_qss)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qss)(); }
   } dummy;
}
