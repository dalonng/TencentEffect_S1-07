// swift-tools-version: 5.10
import PackageDescription

let package = Package(
    name: "TencentEffect_S1_07",
    platforms: [
        .iOS(.v14)
    ],
    products: [
        .library(
            name: "TencentEffect_S1_07",
            targets: ["TencentEffect_S1_07"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "libpag",
            path: "libpag.xcframework"
        ),
        .binaryTarget(
            name: "TECodec",
            path: "TECodec.xcframework"
        ),
        .binaryTarget(
            name: "XMagic",
            path: "XMagic.xcframework"
        ),
        .binaryTarget(
            name: "YTCommonXMagic",
            path: "YTCommonXMagic.xcframework"
        ),
        .target(
            name: "TencentEffect_S1_07",
            dependencies: [
                "libpag",
                "TECodec",
                "XMagic",
                "YTCommonXMagic"
            ],
            resources: [
                .process("Light3DPlugin.bundle"),
                .process("LightBodyPlugin.bundle"),
                .process("LightCore.bundle"),
                .process("LightHandPlugin.bundle"),
                .process("LightSegmentPlugin.bundle"),
                .process("TEPrivacy.bundle")
            ]
        )
    ]
)
