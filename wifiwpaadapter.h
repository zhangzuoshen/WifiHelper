/**
 ** This file is part of the WifiHelper project.
 ** Copyright 2019 张作深 <zhangzuoshen@hangsheng.com.cn>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef WIFIWPAADAPTER_H
#define WIFIWPAADAPTER_H

#include "wifi.h"
#include "wifiaccesspoint.h"
#include "wifinetwork.h"
#include "wifip2pdevice.h"
#include <QLoggingCategory>

// in a header
Q_DECLARE_LOGGING_CATEGORY(wifiWPAAdapter)
Q_DECLARE_LOGGING_CATEGORY(wifiWPAP2P)

class WifiWPAAdapterPrivate;
class WifiWPAAdapter : public QObject
{
    Q_OBJECT
public:
    explicit WifiWPAAdapter(QObject *parent = nullptr);
    ~WifiWPAAdapter();

    bool isOpen() const;

    // 已连接WIFI的SSID
    QString ssid() const;
    // 已连接WIFI的SSID
    QString bssid() const;
    // 已连接WIFI的SSID
    QString ipAddress() const;
    // 已连接WIFI的状态
    QString state();
    // 已连接WIFI的安全认证
    QString security();
    // 已连接WIFI的信号强度
    int rssiValue();
    // 获取当前WiFi接入点列表
    QList<WifiAccessPoint *> accessPoints();
    // 获取当前WiFi网络列表
    QList<WifiNetwork *> networks();
    // 获取当前P2P列表
    QList<WifiP2PDevice *> p2pDevcies();

    int addNetwork(const QString &ssid, const QString &password);
    void selectNetwork(const QString &ssid);
    void selectNetwork(int id);
    void removeNetwork(int id);

signals:
    void isOpenChanged();
    void statusChanged();
    void accessPointsChanged();
    void networksChanged();
    void p2pDeviceFound(int index);
    void p2pDeviceCleared();

public slots:
    void open();
    void close();

    bool connect();
    bool disconnect();
    void saveConfig();
    void scan();

    void p2p_start();
    void p2p_stop();
    void p2p_connectPBC(const QString &address);

private:
    Q_DECLARE_PRIVATE(WifiWPAAdapter)
};

#endif // WIFIWPAADAPTER_H
