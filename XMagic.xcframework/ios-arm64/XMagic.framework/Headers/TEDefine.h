//
//  TEDefine.h
//  BeautyDemo
//
//  Created by chavezchen on 2022/8/22.
//

#ifndef TEDefine_h
#define TEDefine_h

#pragma mark - category常用定义
static NSString * const kTEBackgroundPlane = @"background_plane";       // 背景
static NSString * const kTEHairStyle = @"hair_style";                   // 发型
static NSString * const kTEHairColor = @"hair_color";                   // 发色
static NSString * const kTESkinColor = @"skin_color";                   // 皮肤颜色
static NSString * const kTEFaceType = @"face_type";                     // 脸型
static NSString * const kTEFaceShapeValue = @"face_shape_value";        // 脸部微调
static NSString * const kTEFaceMakeup = @"face_makeup";                 // 脸妆
static NSString * const kTEEyebrowStyle = @"eyebrow_style";             // 眉型
static NSString * const kTEEyebrowColor = @"eyebrow_color";             // 眉毛颜色
static NSString * const kTEEyebrowShapeValue = @"eyebrow_shape_value";  // 眉毛微调
static NSString * const kTEEyesMakeup = @"eyes_makeup";                 // 眼妆
static NSString * const kTEEyeballStyle = @"eyeball_style";             // 瞳孔颜色
static NSString * const kTEEyesShapeValue = @"eyes_shape_value";        // 眼睛微调
static NSString * const kTENoseShapeValue = @"nose_shape_value";        // 鼻子微调
static NSString * const kTEMouthShapeValue = @"mouth_shape_value";      // 嘴微调
static NSString * const kTELipMakeup = @"lip_makeup";                   // 嘴唇妆
static NSString * const kTEBeardMakeup = @"beard_makeup";               // 胡子
static NSString * const kTEEarphone = @"earphone";                      // 耳机
static NSString * const kTEEarring = @"earring";                        // 耳环
static NSString * const kTEGlass = @"glass";                            // 眼镜
static NSString * const kTEHat = @"hat";                                // 帽子
static NSString * const kTEDressTop = @"dress_top";                     // 衣服
static NSString * const kTEDressBottom = @"dress_bottom";               // 裤子
static NSString * const kTEShoes = @"shoes";                            // 鞋子
static NSString * const kTENeckColor = @"neck_color";                   // 脖子颜色
static NSString * const kTELens = @"lens";                              // 镜片
static NSString * const kTEEyelashesStyle = @"eyelashes_style";         // 睫毛

#pragma mark - action常用定义
static NSString * const kTEActionChangeColor = @"changeColor";               // 颜色修改
static NSString * const kTEActionChangeTexture = @"changeTexture";           // 替换纹理贴图
static NSString * const kTEActionShapeValue = @"shapeValue";                 // 数值调整
static NSString * const kTEActionReplace = @"replace";                       // 替换模型
static NSString * const kTEActionBasicTransform = @"basicTransform";         // 调整位置

#pragma mark - AvatarCustomEventKey
// 开启无人脸时的闲置状态        
static NSString * const ENABLE_AVATAR_IDLE_EXPRESSION = @"ENABLE_AVATAR_IDLE_EXPRESSION";

#pragma mark - FeatureName
// 52表情配置
static NSString * const ANIMOJI_52_EXPRESSION = @"ai.3dmmV2.enable";
static NSString * const BODY_3D_POINT = @"ai.body3dpoint.enable";
static NSString * const HAND_DETECT = @"ai.hand.enable";
static NSString * const BEAUTY_ONLY_WHITEN_SKIN = @"beauty.onlyWhitenSkin";
static NSString * const SEGMENTATION_SKIN = @"ai.segmentation.skin.enable";
static NSString * const SEGMENTATION_FACE_BLOCK = @"ai.segmentation.faceBlock.enable";
static NSString * const AI_FACE_STATIC_FEATURE_ENABLE = @"ai.faceStaticFeature.enable";
static NSString * const SMART_BEAUTY = @"auto_beauty_switch";

#pragma mark - 基础数据类型
/// @brief 原始数据支持的格式类型
typedef enum YTImageRawDataType_t
{
    YT_IMG_BGRA,
    YT_IMG_YUV_420SP
}YTImageRawDataType;

/// @brief 美颜SDK 日志等级
typedef NS_ENUM(NSInteger, YtSDKLoggerLevel)
{
    /// UNKNOWN级别
    YT_SDK_UNKNOWN_LEVEL = 0,
    /// DEFAULT 级别
    YT_SDK_DEFAULT_LEVEL,
    /// VERBOSE级别
    YT_SDK_VERBOSE_LEVEL,
    /// DEBUG 级别
    YT_SDK_DEBUG_LEVEL,
    /// INFO 级别
    YT_SDK_INFO_LEVEL,
    /// WARN 级别
    YT_SDK_WARN_LEVEL,
    /// ERROR 级别
    YT_SDK_ERROR_LEVEL,
    /// FATAL 级别
    YT_SDK_FATAL_LEVEL
    
};

typedef NS_ENUM(NSInteger, YtLightImageOrigin) {
    YtLightImageOriginTopLeft = 0,
    YtLightImageOriginBottomLeft = 1,
};

typedef NS_ENUM(NSInteger, YtLightDeviceCameraOrientation) {
    YtLightCameraRotationAuto = -1,
    YtLightCameraRotation0 = 0,
    YtLightCameraRotation90 = 1,
    YtLightCameraRotation180 = 2,
    YtLightCameraRotation270 = 3,
};

typedef NS_ENUM(NSInteger, TEFlipType) {
    TEFlipTypeNo = 0,
    TEFlipTypeHorizontal = 1, // 水平翻转
    TEFlipTypeVertical = 2,   // 垂直翻转
};

/// 输入输出数据类型
enum YTProcessDataType {
    kYTImagePixelData,
    kYTTextureData,
    kYTImageRawData,
    kYTUIImageData
};

typedef NS_ENUM(NSInteger, TEAvatarErrorCode) {
    TEAvatarErrorCodeNoAuth = 1,                // 没有权限
    TEAvatarErrorCodeResInValid = 5,            // 传入的Avatar素材路径无效
    TEAvatarErrorCodePhotoInValid = 10,         // 读取照片失败
    TEAvatarErrorCodeNetReqFailed = 20,         // 网络请求失败
    TEAvatarErrorCodeNetResParseFailed = 30,    // 网络返回数据解析失败
    TEAvatarErrorCodeAnalyzeFailed = 40,        // 人脸分析失败
    TEAvatarErrorCodeAvatarSourceEmpty = 50     // 加载Avatar源数据失败
};

#endif /* TEDefine_h */
