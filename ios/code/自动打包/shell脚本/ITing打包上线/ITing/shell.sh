#使用方法

if [ ! -d ./IPADir ];
    then
        mkdir -p IPADir;
fi
# 删除build包
if [[ -d build ]]; then
rm -rf build -r
fi


#工程绝对路径
project_path=$(cd `dirname $0`; pwd)

#工程名 将XXX替换成自己的工程名
project_name=ITing

#scheme名 将XXX替换成自己的sheme名
scheme_name=ITing

#打包模式 Debug/Release
development_mode=Release

#build文件夹路径
build_path=${project_path}/build

#plist文件所在路径
exportOptionsPlistPath=${project_path}/exportAppstore.plist

#导出.ipa文件所在路径
exportIpaPath=${project_path}/IPADir/${development_mode}

echo "请输入你想法发布的方式 ? [ 1:app-store 2:ad-hoc] "

##
read number
    while([[ $number != 1 ]] && [[ $number != 2 ]])
    do
        echo "笨蛋，只能输入 1 or 2"
        echo "请输入你想法发布的方式 ? [ 1:app-store 2:ad-hoc] "
        read number
    done

if [ $number == 1 ];
    then
    development_mode=Release
    exportOptionsPlistPath=${project_path}/exportAppstore.plist
## 证书名字

    else
    development_mode=Release
    exportOptionsPlistPath=${project_path}/exportTest.plist

fi


echo '///-----------'
echo '/// 正在清理工程'
echo '///-----------'
xcodebuild \
clean -configuration ${development_mode} -quiet  || exit


echo '///--------'
echo '/// 清理完成'
echo '///--------'
echo ''

echo '///-----------'
echo '/// 正在编译工程:'${development_mode}
echo '///-----------'
xcodebuild \
archive -workspace ${project_path}/${project_name}.xcworkspace \
-scheme ${scheme_name} \
-configuration ${development_mode} \
-archivePath ${build_path}/${project_name}.xcarchive -quiet  || exit

echo '///--------'
echo '/// 编译完成'
echo '///--------'
echo ''

echo '///----------'
echo '/// 开始ipa打包'
echo '///----------'
xcodebuild -exportArchive -archivePath ${build_path}/${project_name}.xcarchive \
-configuration ${development_mode} \
-exportPath ${exportIpaPath} \
-exportOptionsPlist ${exportOptionsPlistPath} \
-quiet || exit

# 删除build包
if [[ -d build ]]; then
rm -rf build -r
fi


if [ -e $exportIpaPath/$scheme_name.ipa ];
    then
    echo '///----------'
    echo '/// ipa包已导出'
    echo '///----------'
    open $exportIpaPath
    else
    echo '///-------------'
    echo '/// ipa包导出失败 '
    echo '///-------------'
fi
echo '///------------'
echo '/// 打包ipa完成  '
echo '///-----------='
echo ''

echo '///-------------'
echo '/// 开始发布ipa包 '
echo '///-------------'

if [ $number == 1 ];
    then

    #验证并上传到App Store
    # 将-u 后面的XXX替换成自己的AppleID的账号，-p后面的XXX替换成自己的密码
    altoolPath="/Applications/Xcode.app/Contents/Applications/Application Loader.app/Contents/Frameworks/ITunesSoftwareService.framework/Versions/A/Support/altool"

# appstore 验证你的账号 accout + password
    "$altoolPath" --validate-app -f ${exportIpaPath}/${scheme_name}.ipa -u product@rocedar.com [-p Pro_1108]
# 双重验证 : account + specialPassword
    "$altoolPath" --upload-app -f ${exportIpaPath}/${scheme_name}.ipa -u  1900006358@qq.com -p geak-ksza-jjhe-nqhi
else

    echo "请输入你要发布的平台 ? [ 1:fir 2:蒲公英] "
    ##
    read platform
        while([[ $platform != 1 ]] && [[ $platform != 2 ]])
        do
            echo "笨蛋，只能输入 1 or 2"
            echo "请输入你要发布的平台 ? [ 1:fir 2:蒲公英] "
            read platform
        done

            if [ $platform == 1 ];
                then
                #上传到Fir
                # 将XXX替换成自己的Fir平台的token
                fir login -T d58c5754d2aff40b4d883ddfefa0d079
                fir publish $exportIpaPath/$scheme_name.ipa
            else
                echo "开始上传到蒲公英"
                #上传到蒲公英
                #蒲公英aipKey
                MY_PGY_API_K=8f6637a41c64e901781a776ab1caaccc
                #蒲公英uKey
                MY_PGY_UK=2f778b73218f22145d152600eeee86b1


                curl -F "file=@${exportIpaPath}/${scheme_name}.ipa" -F "uKey=${MY_PGY_UK}" -F "_api_key=${MY_PGY_API_K}" https://qiniu-storage.pgyer.com/apiv1/app/upload
            fi
fi
echo "\n\n"
echo "已运行完毕>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
exit 0

