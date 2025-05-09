//
//  XMagic.h
//  XMagic
//
//  Created by MarxWang on 2021/4/8.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "TEDefine.h"

#pragma mark - 事件回调接口
/// @brief SDK内部事件回调接口     SDK internal event callback interface
@protocol YTSDKEventListener <NSObject>
/// @brief AI事件回调     AI event callback
/// @param event dict格式的回调     dict  format callback
- (void)onAIEvent:(id _Nonnull)event;
/// @brief 提示事件回调     Prompt event callback
/// @param event dict格式的回调     dict  format callback
- (void)onTipsEvent:(id _Nonnull)event;
/// @brief 资源包事件回调     Asset event callback
/// @param event string格式的回调     string format callback
- (void)onAssetEvent:(id _Nonnull)event;

@end

@protocol YTSDKLogListener <NSObject>
/// @brief 日志监听回调Block     Log monitoring callback
/// @param loggerLevel 返回当前日志等级     Return the current log level
/// @param logInfo 返回当前日志信息     Return the current log information
- (void)onLog:(YtSDKLoggerLevel) loggerLevel withInfo:(NSString * _Nonnull) logInfo;
@end

#pragma mark - 处理相关数据类型     Handle related data types

/// @brief Pixel数据类型     Pixel data type
@interface YTImagePixelData : NSObject
/// 相机Pixel数据     Camera Pixel data
@property (nonatomic, assign) CVPixelBufferRef _Nullable data;
/// 相机旋转方向     Camera rotation direction
@property (nonatomic, assign) int rotation;
/// 相机采样时间     Camera sampling time
@property (nonatomic, assign) CMTime sampleTime;
@end

/// @brief Texture数据类型     Texture data type
@interface YTTextureData : NSObject
/// GL纹理ID     GL texture ID
@property (nonatomic, assign) int texture;
/// 纹理宽     texture width
@property (nonatomic, assign) int textureWidth;
/// 纹理高     texture height
@property (nonatomic, assign) int textureHeight;
@end
/// @brief 原始数据类型     Raw data type
@interface YTImageRawData  : NSObject
/// 原始数据        Raw data
@property (nonatomic, assign) void * _Nullable data;
/// 原始数据宽      Raw data width
@property (nonatomic, assign) int width;
/// 原始数据高      Raw data height
@property (nonatomic, assign) int height;
/// 原始数据像素宽     raw data pixel width
@property (nonatomic, assign) int stride;
/// 原始数据类型暂时只支持BGRA格式参考@see YTImageRawDataType     Raw data type refer to @see YTImageRawDataType,only support BGRA
@property (nonatomic, assign) YTImageRawDataType type;
/// 时间戳     timestamp
@property (nonatomic, assign) double timeStamp;
@end
/// @brief UIImage数据类型     UIImage data type
@interface YTUIImageData : NSObject
/// UIImage数据     UIImage data
@property (nonatomic, assign) UIImage * _Nullable data;
@end

/// @brief 处理输入4选1     Process input 4 choose 1
@interface YTProcessInput : NSObject
/// 相机数据对象     camera data object
@property (nonatomic, strong) YTImagePixelData * _Nullable pixelData;
/// 纹理对象     texture object
@property (nonatomic, strong) YTTextureData * _Nullable textureData;
/// 原始数据对象     raw data object
@property (nonatomic, strong) YTImageRawData * _Nullable rawData;
/// UIImage对象     UIImage object
@property (nonatomic, strong) YTUIImageData * _Nullable UIImageData;
/// 输入数据类型     input data type
@property (nonatomic) enum YTProcessDataType dataType;
@end
/// @brief 处理输出     process output
@interface YTProcessOutput : NSObject
/// 纹理输出对象（一定会有）    Texture output object (always output)
@property (nonatomic, strong) YTTextureData * _Nullable textureData;
/// 相机输出对象（如果输入是相机采集数据）    Camera output object (if the input is camera acquisition data)
@property (nonatomic, strong) YTImagePixelData * _Nullable pixelData;
/// 原始输出对象（如果输入是原始数据）    raw output object (if input is raw data)
@property (nonatomic, strong) YTImageRawData * _Nullable rawData;
/// UIImage输出对象（如果输入是UIImage对象）     UIImage output object (if the input is a UIImage object)
@property (nonatomic, strong) YTUIImageData * _Nullable UIImageData;
/// 输出数据类型     output data type
@property (nonatomic) enum YTProcessDataType dataType;
@end

/// @brief 美颜属性配置类型     Beauty property configuration type
@interface YTBeautyPropertyInfo : NSObject
/// 属性名称     property name
@property (nonatomic, strong) NSString * _Nonnull name;
/// 属性最小值     property minimum value
@property (nonatomic, strong) NSNumber * _Nullable minValue;
/// 属性最大值     property maximum value
@property (nonatomic, strong) NSNumber * _Nullable maxValue;
/// 当前属性/默认属性值     current property/default property value
@property (nonatomic, strong) NSNumber * _Nullable curValue;

/// @brief 属性初始化函数     property initialization function
/// @param name 属性名称     property name
/// @param min 属性最小值     property minimum value
/// @param max 属性最大值     property maximum value
/// @param cur 属性默认/当前值     current property/default property value
/// @return 成功返回属性对象/失败返回nil     Return property object on success/nil on failure
- (instancetype _Nonnull)initWith:(NSString* _Nonnull)name withMin:(NSNumber * _Nonnull)min withMax:(NSNumber * _Nonnull)max withCur:(NSNumber * _Nonnull)cur;
@end

typedef NS_ENUM(NSInteger, DeviceLevel) {
    DEVICE_LEVEL_VERY_LOW = 1,
    DEVICE_LEVEL_LOW = 2,
    DEVICE_LEVEL_MIDDLE = 3,
    DEVICE_LEVEL_MIDDLE_HIGH = 4,
    DEVICE_LEVEL_HIGH = 5
};

typedef NS_ENUM(NSInteger, AvatarDataType)
{
    /**
     选择型数据。例如眼镜，有多种眼镜，使用时选择一种      Selective data. For example, glasses, there are many kinds of glasses, choose one when using
     */
    AvatarDataTypeSelector = 0,
    /**
     滑杆调节型数据。例如调整脸颊宽度     Slider adjustment data. For example to adjust the cheek width
     */
    AvatarDataTypeSlider
};
@interface AvatarAnimation : NSObject
@property (nonatomic, copy) NSString * _Nullable animPath;
@property (nonatomic, copy) NSString * _Nullable animName;
@property (nonatomic, assign) long animDurationUs;
@end
@interface AnimationPlayConfig : NSObject
@property (nonatomic, copy) NSString * _Nullable entityName;
@property (nonatomic, copy) NSString * _Nullable animPath;
@property (nonatomic, copy) NSString * _Nullable animName;
@property (nonatomic, copy) NSString * _Nullable action;
@property (nonatomic, assign) NSInteger loopCount;
@property (nonatomic, assign) long startPositionUs;

@end
/// @brief 捏脸配置类型     Pinch face configuration type
@interface AvatarData : NSObject
/**
 例如 脸型、眼睛微调 等。TEDefine中定义了标准的category，如果不满足需求，也可以自定义category字符串，跟已有的不冲突即可,不能为空
 For example, face shape, eye fine-tuning, etc. The standard category is defined in TEDefine. If the requirements are not met, the category string can also be customized, as long as it does not conflict with the existing ones, and cannot be empty.
 */
@property (nonatomic, copy) NSString * _Nonnull category;
/**
 标识每一个具体item 或者 每一个微调项。比如每个眼镜都有自己的id。每一个微调项也有自己的id。不能为空
 Identify each specific item or each fine-tuning item. For example, each glasses has its own id. Each spinner also has its own id. Can not be empty
 */
@property (nonatomic, copy) NSString * _Nonnull Id;
// 选择类型或者值类型     select type or value type
@property (nonatomic, assign) AvatarDataType type;
/**
 如果是selector类型，则它表示当前有无被选中
 If it is a selector type, it indicates whether it is currently selected
 */
@property (nonatomic, assign) BOOL isSelected;

/**
 捏身体某个部位 如：脸、眼睛、头发、上衣、鞋子等等。如何设值参考官方文档
 Pinch a certain part of the body such as: face, eyes, hair, coat, shoes and so on. How to set the value refer to the official document
 */
@property (nonatomic, copy) NSString * _Nonnull entityName;
/**
 表示对entityName执行什么操作(action)。 规范参考官方文档
 Indicates what operation (action) to perform on entityName. Specification reference official document
 */
@property (nonatomic, copy) NSString * _Nonnull action;
/**
 表示对entityName执行action操作的具体值。 规范参考官方文档
 Indicates the specific value of the action operation on entityName. Specification reference official document
 */
@property (nonatomic, copy) NSDictionary * _Nonnull value;
@end

/// @brief 拍照捏脸配置数据      Snapping face configuration data
// 眼睛     eye
@interface Eye : NSObject
/**
 识别是否双眼皮。-1:没识别，0:无，1:有
 Identify whether double eyelid. -1: not recognized, 0: no, 1: yes
 */
@property (nonatomic, assign) NSInteger eyelidType;
/**
 眼睛大小。-1:没识别，0:小眼睛，1:普通眼睛，2:大眼睛
 eye size. -1: No recognition, 0: Small eyes, 1: Normal eyes, 2: Big eyes
 */
@property (nonatomic, assign) NSInteger eyeSize;
/**
 识别是否佩戴眼镜。-1:没识别，0:无眼镜，1:普通眼镜，2:墨镜
 Identify whether glasses are worn. -1: No recognition, 0: No glasses, 1: Ordinary glasses, 2: Sunglasses
 */
@property (nonatomic, assign) NSInteger glass;
/**
 识别眼睛是否睁开。-1:没识别，0:睁开，1:闭眼
 Identify if eyes are open. -1: No recognition, 0: Open, 1: Closed eyes
 */
@property (nonatomic, assign) NSInteger eyeOpen;
@end
// 眉毛     Eyebrow
@interface Eyebrow : NSObject
/**
 眉毛长短。0:短眉毛，1:长眉毛
 The length of the eyebrows. 0: short eyebrows, 1: long eyebrows
 */
@property (nonatomic, assign) NSInteger eyebrowLength;
/**
 眉毛浓密。0:淡眉，1:浓眉
 thick eyebrows. 0: light eyebrow, 1: thick eyebrow
 */
@property (nonatomic, assign) NSInteger eyebrowDensith;
/**
 眉毛弯曲。0:不弯，1:弯眉
 The eyebrows are curved. 0: not curved, 1: curved eyebrow
 */
@property (nonatomic, assign) NSInteger eyebrowCurve;
@end
// 头发     Hair
@interface Hair : NSObject
/**
 头发长度信息。0:光头，1:短发，2:中发，3:长发，4:绑发
 Hair length information. 0: bald, 1: short hair, 2: medium hair, 3: long hair, 4: tied hair
 */
@property (nonatomic, assign) NSInteger length;
/**
 刘海信息。0:无刘海，1:有刘海
 Bangs information. 0: no bangs, 1: with bangs
 */
@property (nonatomic, assign) NSInteger bang;
/**
 头发颜色信息。0:黑色，1:金色，2:棕色，3:灰白色
 Hair color information. 0: black, 1: gold, 2: brown, 3: off-white
 */
@property (nonatomic, assign) NSInteger color;
@end
// 帽子     Hat
@interface Hat : NSObject
/**
 帽子佩戴状态。0:不戴帽子，1:普通帽子，2:头盔，3:保安帽子
 The state of wearing the hat. 0: no hat, 1: ordinary hat, 2: helmet, 3: security hat
 */
@property (nonatomic, assign) NSInteger style;
/**
 帽子颜色。0:不戴帽子，1:红色系，2:黄色系，3:蓝色系，4:黑色系，5:灰白色系，6:混色系
 hat color. 0: no hat, 1: red, 2: yellow, 3: blue, 4: black, 5: off-white, 6: mixed color
 */
@property (nonatomic, assign) NSInteger color;
@end

@interface FaceDetailAttributesinfo : NSObject
@property (nonatomic, assign) NSInteger age; // [0,100]
/**
 0:自然，1:高兴，2:惊讶，3:生气，4:悲伤，5:厌恶，6:害怕
 0: Natural, 1: Happy, 2: Surprised, 3: Angry, 4: Sad, 5: Disgusted, 6: Scared
 */
@property (nonatomic, assign) NSInteger emotion;
/**
 性别。-1：没识别，0:男性，1:女性
 gender. -1: not identified, 0: male, 1: female
 */
@property (nonatomic, assign) NSInteger gender;
/**
 眼睛信息
 eye information
 */
@property (nonatomic, strong) Eye * _Nonnull eye;
/**
 眉毛信息
 eyebrow information
 */
@property (nonatomic, strong) Eyebrow * _Nonnull eyebrow;
/**
 头发信息
 hair information
 */
@property (nonatomic, strong) Hair * _Nonnull hair;
/**
 帽子信息
 hat information
 */
@property (nonatomic, strong) Hat * _Nonnull hat;
/**
 是否有口罩，-1:没识别，0:无，1:有
 Whether there is a mask, -1: no recognition, 0: no, 1: yes
 */
@property (nonatomic, assign) NSInteger mask;
/**
 胡子信息。-1:没识别，0:无胡子，1:有胡子
 Beard information. -1: no recognition, 0: no beard, 1: beard
 */
@property (nonatomic, assign) NSInteger moustache;
/**
 鼻子信息。-1:没识别，0:朝天鼻，1:鹰钩鼻，2:普通，3:圆鼻头
 nose information. -1: No recognition, 0: Upturned nose, 1: Hooked nose, 2: Normal, 3: Round nose
 */
@property (nonatomic, assign) NSInteger nose;
/**
 脸型信息。-1:没识别，0:方脸，1:三角脸，2:鹅蛋脸，3:心形脸，4:圆脸
 face information. -1: No recognition, 0: Square face, 1: Triangular face, 2: Oval face, 3: Heart-shaped face, 4: Round face
 */
@property (nonatomic, assign) NSInteger shape;
/**
 肤色信息。-1:没识别，0:黄色皮肤，1:棕色皮肤，2:黑色皮肤，3:白色皮肤
 Skin color information. -1: not identified, 0: yellow skin, 1: brown skin, 2: black skin, 3: white skin
 */
@property (nonatomic, assign) NSInteger skin;
/**
 微笑程度。[0,100]
 Smile level [0,100]
 */
@property (nonatomic, assign) NSInteger smile;
@end

#pragma mark - 美颜SDK对象调用接口     Beauty SDK object call interface

/**
 @brief 美颜SDK调用接口
 包含美颜SDK所覆盖的全部功能接口，注意init和deini需要配套使用，切勿多次init
 Beauty SDK object call interface
 Contains all functional interfaces covered by the Beauty SDK. Note that init and deini need to be used together. Do not init multiple times
 */
@interface XMagic : NSObject
/// @brief SDK版本信息     SDK version information
/// @return 返回当前SDK版本     Return the current SDK version
+(NSString * _Nonnull)version;

/// @brief 初始化接口。   initialization interface
/// @param renderSize 渲染尺寸     render size
/// @param assetsDict 资源Dict     assets Dict
- (instancetype _Nonnull)initWithRenderSize:(CGSize)renderSize
                        assetsDict:(NSDictionary* _Nullable)assetsDict;


/// @brief 初始化接口
/// @param textureID
/// @param width
/// @param height
/// @param flipY

/**
| 资源Key |资源Value说明 | 是否必要 |
| :----  |:----  | :---- |
|  core_name  | 基础美颜资源名称（bundle名字） | 是 |
|  root_path  | 相关资源root路径 | 是 |
|  tnn  | tnn模型名称(bundle名字) | 否 |
|  plugin_3d  | 3d资源名称(bundle名字) | 否 |
|  plugin_hand  | 手势资源名称(bundle名字) | 否 |
|  plugin_segment  | 分割资源名称(bundle名字) | 否 |
**/

/**
|resource Key |resource value description | necessary |
| :----  |:----  | :---- |
|  core_name  | basic beauty resource name (bundle name) | yes |
|  root_path  |related resource root path | yes |
|  tnn  | tnn model name (bundle name) | no |
|  plugin_3d  | 3d esource name (bundle name) | no |
|  plugin_hand  | hand resource name(bundle name) | no |
|  plugin_segment  | segment resource name(bundle name)| no |
**/
- (instancetype _Nonnull)initWithGlTexture:(unsigned)textureID
                        width:(int)width
                        height:(int)height
                        flipY:(bool)flipY
                        assetsDict:(NSDictionary* _Nullable)assetsDict;

/**
 @brief 设置自定义分割背景     Set a custom split background
 @param segmentBgName 背景文件路径（当前素材根目录下的相对路径 或 绝对路径），支持格式png/jpg/pag/mp4/mkv
 Background file path (relative path or absolute path under the root directory of the current material), supports formats png/jpg/pag/mp4/mkv
 @param segmentBgType 背景文件类型 0:图片，1:视频     Background file type 0: image, 1: video
 @param timeOffset 背景视频时长（毫秒）     Background video duration (ms)
 */

/**
|传入时长 timeOffset|处理方式|
| :---- | :---- |
|超过200秒|认为传入值是200秒|
|少于视频本身时长|截取前timeOffset毫秒循环播放|
|超过视频本身时长|超出时长播放视频最后一帧，循环播放|
**/

/**
|Incoming duration timeOffset|processing method|
| :---- | :---- |
|more than 200 seconds|Think the incoming value is 200 seconds|
|less than the length of the video itself|Loop playback in timeOffset milliseconds before interception|
|Exceeds the duration of the video itself | Plays the last frame of the video beyond the duration and plays it in a loop|
**/
- (void)setSegmentBg:(NSString*_Nonnull)segmentBgName segmentBgType:(int)segmentBgType timeOffset:(int)timeOffset;

/// 设置后处理模糊强度（作用于所有模糊组件）    Sets the post-processing blur strength (applies to all blur components)
- (void)emitBlurStrengthEvent:(int)strength;

/// 设置renderSize     set render size
/// 重要：更新renderSize后getCVPixelBuffer会发生变化     Important: getCVPixelBuffer will change after update renderSize
/// @param size 渲染尺寸     render size
- (void)setRenderSize:(CGSize)size;

/// @brief 开启美颜增强模式     Turn on beauty enhancement mode
- (void)enableEnhancedMode;

/// @brief 资源释放接口     resource release interface
- (void)deinit;

/**
 @brief 处理数据接口  2.3.0接口变动：YTProcessInput请务必设置dataType
 Process data interface 2.3.0 interface changes: YTProcessInput must be set to dataType
 @param input 输入处理数据信息     Enter processing data information
 @return 输出处理后的数据信息     Output processed data information
 */
- (YTProcessOutput* _Nonnull)process:(YTProcessInput * _Nonnull)input;

- (YTProcessOutput* _Nonnull)process:(YTProcessInput* _Nonnull)input withOrigin:(YtLightImageOrigin)origin withOrientation:(YtLightDeviceCameraOrientation)orientation;


/**
 @param inputImage 输入图片，建议最大尺寸      2160*4096。超过这个尺寸的图片人脸识别效果不佳或无法识别到人脸，同时容易引起OOM问题，建议把大图缩小后再传入。
 Input image, the recommended maximum size is 2160*4096. If the image exceeds this size, the face recognition effect is not good or the face cannot be recognized, and it is easy to cause OOM problems. It is recommended to reduce the size of the large image before uploading it.
 @param needReset 1、切换图片；2、首次使用分割；3、首次使用动效；4、首次使用美妆 这几种场景needReset设置为true
 1. Switch pictures; 2. Use segmentation for the first time; 3. Use motion effects for the first time; 4. Use beauty makeup for the first time. Set needReset to true for these scenarios
 @return 处理后的图片     processed image
 */
- (UIImage* _Nullable)processUIImage:(UIImage* _Nonnull)inputImage needReset:(bool)needReset;


/// @brief 获取该美颜参数的授权信息     Obtain the authorization information of the beauty parameter
/// @param featureId 配置美颜参数     Configure beauty parameters
/// @return 返回对应美颜参数的授权结果     Return the authorization result corresponding to the beautification parameters
+ (BOOL)isBeautyAuthorized:(NSString * _Nullable)featureId;


+ (DeviceLevel)getDeviceLevel;

/// @brief 点击事件回调     Click event callback
/// @param event LightTouchEvent格式的回调     LightTouchEvent format callback
- (void)onTouch:(id _Nonnull)event;

/// @brief 配置美颜各种效果（使用方法可参考文档和demo）     Configure various effects of beauty（refer to the documentation and demo for usage instructions.）
/// @param effectName 效果类型 字符串： lut, motion......     property type String:  lut, motion......
/// @param effectValue 效果数值     property value
/// @param resourcePath 素材路径 resource path
/// @param extraInfo 预留扩展, 附加额外配置dict     reserved extension, additional configuration dict
- (void)setEffect:(NSString * _Nullable)effectName
      effectValue:(int)effectValue
     resourcePath:(NSString * _Nullable)resourcePath
        extraInfo:(NSDictionary * _Nullable)extraInfo;

/// @brief 配置美颜各种效果     Configure various effects of beauty
/// @param propertyType 效果类型 字符串：beauty, lut, motion     property type String: beauty, lut, motion
/// @param propertyName 效果名称     property name
/// @param propertyValue 效果数值     property value
/// @param extraInfo 预留扩展, 附加额外配置dict     reserved extension, additional configuration dict
/// @return 成功返回0，失败返回其他     Return 0 on success, other on failure
/// @note 具体说明     Specific instructions
/**
| 效果类型 | 效果名称 | 效果值 | 说明  | 备注 |
| :---- | :---- |:---- | :---- | :---- |
|  beauty  | 美颜id名称 | 美颜效果强度数值 |美颜类型配置接口 | 无 |
|  lut  | 滤镜路径+滤镜名称 | 滤镜强度数值 | 滤镜类型配置接口 | 无 |
|  motion  | 动效路径名称 | 动效路径 | 动效类型配置接口| **注意**：如果资源中有zip，请确保传入动效路径为可写路径，否则跟app包走需要手动unzip才可以使用 |

 | propertyType | propertyName| propertyValue | instructions  |remark  |
 | :---- | :---- |:---- | :---- | :---- |
 |  beauty  | beauty id name|beauty effect intensity value  |beauty type configuration interface  |none  |
 |  lut  |lut path + lut name  | lut strength value | lut type configuration interface | none |
 |  motion  | motion path name | motion path | motion type configuration interface| **
 **Notice **：If there is a zip in the resource, please make sure that the incoming animation path is a writable path, otherwise you need to manually unzip it before you can use it with the app package |
**/
- (int)configPropertyWithType:(NSString *_Nonnull)propertyType withName:(NSString *_Nonnull)propertyName withData:(NSString*_Nonnull)propertyValue withExtraInfo:(id _Nullable)extraInfo DEPRECATED_MSG_ATTRIBUTE("Please use setEffectWithName:withValue:withPath:withExtraInfo:");


/// @brief 获取美颜参数配置信息     Obtain beauty parameter configuration information
/// @param propertyName 配置名称     propertyName
/// @return 返回对应配置信息     Return corresponding configuration information
- (YTBeautyPropertyInfo * _Nullable)getConfigPropertyWithName:(NSString *_Nonnull)propertyName;

/// @brief 日志注册接口     log registration interface
/// @param listener 日志回调接口     Log callback interface
/// @param level 日志输出level，默认ERROR      log output level, default ERROR
- (void)registerLoggerListener:(id<YTSDKLogListener> _Nullable)listener withDefaultLevel:(YtSDKLoggerLevel)level;

/// @brief 日志注册静态接口，可在XMagic初始化之前调用     log registration interface
/// @param level 日志输出level，默认ERROR      log output level, default ERROR
/// @param listener 日志回调接口     Log callback interface
+ (void)setXmagicLogLevel:(YtSDKLoggerLevel)level listener:(id<YTSDKLogListener> _Nullable)listener;


/**
 @brief SDK事件监听接口     SDK event monitoring interface
 @param listener 事件监听器回调，主要分为AI事件，Tips提示事件，Asset事件
 Event listener callback, mainly divided into AI events, Tips reminder events, Asset events
 */
- (void)registerSDKEventListener:(id<YTSDKEventListener> _Nullable)listener;

/// @brief 注册回调清理接口     Register callback cleanup interface
- (void)clearListeners;

/// @brief 获取当前GL上下文接口     Get the current GL context interface
- (nullable EAGLContext*)getCurrentGlContext;

/// @brief 导出当前形象的图片     Export a picture of the current image
- (void)exportCurrentTexture:(nullable void (^)(UIImage *_Nullable image))callback;

- (void)setImageOrientation:(YtLightDeviceCameraOrientation)orientation;
#pragma mark - Avatar
/**
 加载avatar素材     Load avatar material
 @param resPath 素材根路径
 material root path
 @param exportedAvatar 导出的数据。会根据传入的该数据进行形象的初始化，如果传nil则使用素材的默认形象
 Exported data. The image will be initialized according to the incoming data, if nil is passed, the default image of the material will be used
 @param completion 回调，可为nil。方法内会对传入的avatar对应素材进行检查，如果素材有缺失会返回失败和对应无效的对象
 callback, can be nil. The method will check the material corresponding to the incoming avatar, if the material is missing, it will return failure and the corresponding invalid object
 @return 同步回调     synchronous callback
 */
- (BOOL)loadAvatar:(NSString * _Nullable)resPath exportedAvatar:(NSString * _Nullable)exportedAvatar completion:(nullable void (^)(BOOL success, NSArray <AvatarData *>* _Nullable invalidAvatarList))completion;

/**
 捏脸/换装接口，调用后实时更新当前素材呈现出的形象。一个AvatarConfig对象是一个原子配置(如换发型)
 一次可以传入多个原子配置(比如既换发型，又换发色)
 Face pinch/dressup interface, after calling, update the image presented by the current material in real time. An AvatarConfig object is an atomic configuration (such as changing hairstyles)
  Multiple atomic configurations can be passed in at a time (such as changing both hairstyles and hair colors)
 @param avatarDataList 配置数组     configuration array
 @param completion 回调，可为nil。方法内会对传入的avatar对应素材进行检查，如果素材有缺失会返回失败和对应无效的对象
 callback, can be nil. The method will check the material corresponding to the incoming avatar, if the material is missing, it will return failure and the corresponding invalid object
 */
- (void)updateAvatar:(NSArray<AvatarData *> *_Nonnull)avatarDataList completion:(nullable void (^)(BOOL success, NSArray <AvatarData *>* _Nullable invalidAvatarList))completion;

/**
 发送自定义事件，如：开启无人脸时的闲置显示状态
 Send custom events, such as: open the idle display state when there is no face
 @param eventKey 自定义事件key,可参考TEDefine的AvatarCustomEventKey
               For custom event key, please refer to AvatarCustomEventKey of TEDefine
 @param eventValue 自定义事件value，为json字符串
                Custom event value, which is a json string
 */
- (void)sendCustomEvent:(NSString * _Nullable)eventKey eventValue:(NSString * _Nullable)eventValue;

/**
 获取avatar源数据。会根据exportedAvatar参数修改素材的选中状态，exportedAvatar为nil则是默认选中状态
 Get avatar source data. The selected state of the material will be modified according to the exportedAvatar parameter, and the exportedAvatar is nil, which is the default selected state
 @param resPath 素材文件路径     Material file path
 @param exportedAvatar exportAvatar:接口返回的数据,可为nil     exportAvatar: The data returned by the interface can be nil
 @return key是数据的category(详见TEDefine的category规范),value是这个category下面的全部数据
 The key is the category of the data (see the category specification of TEDefine for details), and the value is all the data under this category
 */
+ (NSDictionary <NSString *, NSArray *>* _Nullable)getAllAvatarConfig:(NSString * _Nullable)resPath exportedAvatar:(NSString *_Nullable)exportedAvatar;

/**
 导出捏脸数据     Export pinch face data
 @param avatarDataList 需要导出的avatart数据     Avatart data that needs to be exported
 @return 导出的字符串,可以自行保存，下次加载素材时(loadAvatar:...)设置给 exportedAvatar参数
 The exported string can be saved by itself, and set to the exportedAvatar parameter when the material is loaded next time (loadAvatar:...)
 */
+ (NSString *_Nullable)exportAvatar:(NSArray <AvatarData *>*_Nullable)avatarDataList;

/**
 添加素材配置信息,某个单独素材配置需要通过网络下载的，下载之后调用此接口增加配置
 Add material configuration information. A single material configuration needs to be downloaded through the network. After downloading, call this interface to add configuration
 @param rootPath 素材目录路径     Material directory path
 @param category 类型     category
 @param filePath 需要添加配置对应的地址     The filePath corresponding to the configuration needs to be added
 @param completion 回调     callback
 */
+ (void)addAvatarResource:(NSString * _Nullable)rootPath category:(NSString * _Nullable)category filePath:(NSString * _Nullable)filePath completion:(nullable void (^)(NSError * _Nullable error, NSArray <AvatarData *>* _Nullable avatarList))completion;

/**
 拍照捏脸接口，需要联网使用。要求传入照片路径和素材包路径，SDK解析该素材包的avatar数据，与照片特征进行匹配。
 The pinch face interface for taking photos requires networking. It is required to pass in the path of the photo and the path of the material package. The SDK parses the avatar data of the material package and matches it with the characteristics of the photo.
 @param photoPath 照片路径，请确保人脸位于画面中间。建议画面中只包含一个人脸，如果有多个人脸，SDK会随机选择一个。建议照片的短边大于等于500px，否则可能影响识别效果。
 photo path, please make sure the face is in the center of the frame. It is recommended that only one face be included in the screen. If there are multiple faces, the SDK will randomly select one. It is recommended that the short side of the photo be greater than or equal to 500px, otherwise the recognition effect may be affected.
 @param avatarResPaths 你可以传入多套Avatar素材，SDK会根据照片分析的结果，选择一套最合适的素材进行自动捏脸。注：目前只支持一套，如果传入多套，SDK只会使用第一套。
 You can pass in multiple sets of Avatar materials, and the SDK will select the most suitable set of materials for automatic face pinching based on the results of photo analysis. Note: Currently only one set is supported, if multiple sets are passed in, the SDK will only use the first set.
 @param isMale 是否为男性     Is it male
 @param success 成功回调     success callback matchedResPath:匹配的素材路径。srcData:匹配结果，与上文中的exportAvatar接口返回的是一样的含义
 matchedResPath:Matching footage path. srcData: the matching result, which has the same meaning as that returned by the exportAvatar interface above
 @param failure 失败回调 code:错误码。msg:错误信息
 */

+ (void)createAvatarByPhoto:(NSString * _Nullable)photoPath avatarResPaths:(NSArray <NSString *>* _Nullable)avatarResPaths isMale:(BOOL)isMale success:(nullable void (^)(NSString *_Nullable matchedResPath, NSString *_Nullable srcData))success failure:(nullable void (^)(TEAvatarErrorCode code, NSString *_Nullable msg))failure;

+ (void)getFaceFeatureFromPhoto:(UIImage * _Nullable)image success:(nullable void (^)(FaceDetailAttributesinfo *_Nullable faceInfo))success failure:(nullable void (^)(TEAvatarErrorCode errorCode, NSString *_Nullable msg))failure;

/// @brief 设置某个特性的开或关     Set a feature on or off
/// @param featureName 取值见TEDefine FeatureName
/// @param enable 开或关     on or off
- (void)setFeatureEnableDisable:(NSString *_Nonnull)featureName enable:(BOOL)enable;

/// 根据语音数据更新表情     Update emoticons based on voice data
/// @param standard52Exp 52个语音数据     52 voice data
- (void)updateAvatarByExpression:(NSArray *_Nonnull)standard52Exp;

/// 获取 avatar动画配置   get avatar animation config
/// @param avatarResPath  素材路径 Material directory path
+ (NSArray <AvatarAnimation *> *_Nullable)getAvatarAnimations:(NSString *_Nonnull)avatarResPath;

/// 设置 avatar动画   set avatar animation
/// @param animationPlayConfig  AnimationPlayConfig配置
- (void)playAvatarAnimation:(AnimationPlayConfig *_Nullable)animationPlayConfig;

/**
 @brief 设置模型文件  set up model file path
 @param agentPathMap 模型文件名称和对应的路径 Model file name and corresponding path
 例如：NSDictionary *dic = @{
 @"Ace_3d_Engine":@"Light3DPlugin.bundle的路径",
 @"HAND_AGENT": @"LightHandModel.bundle的路径",
 @"BODY_AGENT": @"LightBodyModel.bundle的路径",
 @"BODY3D_POINT_AGENT":"LightBody3DModel.bundle的路径",
 @"BG_SEG_AGENT":"LightSegmentBody.bundle的路径",
 @"HEAD_SEG_AGENT":"LightSegmentHead.bundle的路径",
 @"HAIR_SEG_AGENT":"LightSegmentHair.bundle的路径"
 };
 */
-(void)setBundleToLightEngine:(NSDictionary *_Nullable)agentPathMap;


#pragma mark AI数据接口     AI data interface
/// @brief AI数据回调接口     AI data callback interface
/// @note json string结构，最多返回5个人脸信息     json string structure, return up to 5 face information
/**
 ~~~~~~~~~~~~~~~{.json}
{
 "face_info":[{
  "trace_id":5,
  "face_256_point":[
    180.0,
    112.2,
    ...
  ],
  "face_256_visible":[
    0.85,
    ...
  ],
  "out_of_screen":true,
  "left_eye_high_vis_ratio:1.0,
  "right_eye_high_vis_ratio":1.0,
  "left_eyebrow_high_vis_ratio":1.0,
  "right_eyebrow_high_vis_ratio":1.0,
  "mouth_high_vis_ratio":1.0
 },
 ...
 ]
}
 ~~~~~~~~~~~~~~~
**/

//TODO: add view lifecycle related interfaces
/// @brief APP暂停时候需要调用SDK暂停接口     When the APP is paused, the SDK pause interface needs to be called
- (void)onPause;
/// @brief APP恢复时候需要调用SDK恢复接口     When the APP is restored, the SDK restoration interface needs to be called
- (void)onResume;

/// @brief 设置静音 set mute
- (void)setAudioMute:(BOOL)isMute;
@end
