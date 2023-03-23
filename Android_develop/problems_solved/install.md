# 配置Android开发环境

## 下载gradle

> 官网下载链接：https://gradle.org/releases/

* ### 添加环境变量

  #### 新建： `GRADLE_HOME `环境变量指向你的 `Gradle `解压路径（ `这里看大家安装的路径，不一定一样 `）

![在这里插入图片描述](install.assets/76f4c90dc91a4ab8b2ff88b9645fd02d.png)

#### 将 `%GRADLE_HOME%\bin `添加到 `Path `环境变量中，然后点击确定

![在这里插入图片描述](install.assets/96c9dce29fd3421b8abdc5d8c2b4eaed.png)



* ### 配置镜像仓库：

### 打开 `\gradle-7.4.2\init.d\` 下的 `init.gradle`(没有就新建一个文件)

**添加如下配置( `这里我们使用【 `阿里云镜像 `】建议配置,下载速度比较快 `)**

```json
allprojects {
    repositories {
 
        mavenLocal()
 
        maven { url 'https://maven.aliyun.com/repository/public/' }
        maven { url 'https://maven.aliyun.com/repository/spring/'}
    	maven { url 'https://maven.aliyun.com/repository/google/'}
    	maven { url 'https://maven.aliyun.com/repository/gradle-plugin/'}
    	maven { url 'https://maven.aliyun.com/repository/spring-plugin/'}
    	maven { url 'https://maven.aliyun.com/repository/grails-core/'}
	    maven { url 'https://maven.aliyun.com/repository/apache-snapshots/'}
        
        mavenCentral()
    }
}
```

* ### 配置本地仓库:

![在这里插入图片描述](https://img-blog.csdnimg.cn/c3e20085703d405884577d80f35e4860.png)

变量名：`GRADLE_USER_HOME`
变量值：自定义 `Gradle` 仓库目录

![在这里插入图片描述](install.assets/fe00a4a47c85463990bd4ed0c366331e.png)

* ### IDEA配置

  ![在这里插入图片描述](https://img-blog.csdnimg.cn/523bb80adc6941c0abbea3f9f2df7896.png)