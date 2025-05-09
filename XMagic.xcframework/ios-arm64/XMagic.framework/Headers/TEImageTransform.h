//
//  TEImageTransform.h
//  BeautyDemo
//
//  Created by chavezchen on 2023/6/15.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import "TEDefine.h"

NS_ASSUME_NONNULL_BEGIN

//  数据格式 Data format
typedef NS_ENUM(NSInteger, TEPixelFormatType) {
    //    {zh} 未知格式        {en} Unknown format
    TE_UNKNOW,
    // 8bit kCVPixelFormatType_32BGRA
    TE_BGRA,
    // video range, kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange
    TE_NV12V,
    // full range, kCVPixelFormatType_420YpCbCr8BiPlanarFullRange
    TE_NV12F
};



@interface TEImageTransform : NSObject

/// 初始化工具类
/// @param context 如果使用本类OpenGL接口,建议使用本方法初始化,context可传[xMgiac getCurrentGlContext]
- (instancetype)initWithEAGLContext:(EAGLContext *)context;

/// @brief CVPixelBufferRef yuv/rgb相互转换接口，目前只支持TEPixelFormatType内的三种类型转换   CVPixelBufferRef yuv/rgb transfor interface
/// @param pixelBuffer 输入pixelBuffer     input pixelBuffer
/// @param outputFormat 指定输出pixelBuffer的类型    out pixelBuffer format
- (CVPixelBufferRef)transformCVPixelBufferToBuffer:(CVPixelBufferRef)pixelBuffer outputFormat:(TEPixelFormatType)outputFormat;

/// 将yuv/rgb pixelBuffer转换为bgra格式的纹理id
/// @param pixelBuffer 输入pixelBuffer
- (GLuint)transformPixelBufferToBGRATexture:(CVPixelBufferRef)pixelBuffer;

/// 对CVPixelBufferRef进行旋转和镜像翻转, 如果同时传旋转和镜像，处理逻辑为先镜像再旋转
/// @param pixelBuffer 输入pixelBuffer  input pixelBuffer
/// @param rotation 旋转角度
/// @param flipType 镜像类型,水平镜像or垂直镜像
- (CVPixelBufferRef)convertCVPixelBuffer:(CVPixelBufferRef)pixelBuffer rotaion:(YtLightDeviceCameraOrientation)rotation flip:(TEFlipType)flipType;

/// 对纹理Id进行旋转/镜像翻转,如果同时传旋转和镜像，处理逻辑为先镜像再旋转
/// @param srcId 输入的textureId
/// @param width texture width
/// @param height texture height
/// @param rotation 逆时针旋转角度
/// @param flipType 翻转类型
- (GLuint)convert:(GLuint)srcId width:(int)width height:(int)height rotaion:(YtLightDeviceCameraOrientation)rotation flip:(TEFlipType)flipType;

/// 对纹理Id进行裁剪
/// @param srcId 输入的textureId
/// @param width texture width
/// @param height texture height
/// @param cropScale 裁剪掉多少比例，取值范围0-1。比如整体裁剪掉10%，就传0.1，代表上下左右四周各裁剪5%，再放大到输入相同的尺寸
- (GLuint)crop:(GLuint)srcId width:(int)width height:(int)height cropScale:(float)cropScale;

/// @param outId 将裁剪后的纹理渲染到outId对应的纹理上
- (void)crop:(GLuint)srcId outId:(GLuint)outId width:(int)width height:(int)height cropScale:(float)cropScale;
@end

NS_ASSUME_NONNULL_END
