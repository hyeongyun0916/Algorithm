import requests
import time

url = "https://ucselfopen.mobing.co.kr/api/v1/bc/num"
headers = {
    "Content-Type": "application/json"
}
data = {
    "serviceJoinSeq": "13188515",
    "userNM": "최경희",
    "userType": "adult",
    "joinType": "NEW",
    "planID": "LPZ0012398",
    "phID": None,
    "usimPrchs": None,
    "usimType": "ESIM",
    "usimAmt": None,
    "phoneAmt": None,
    "chargeAmt": None,
    "orderId": None,
    "joinUsim": None,
    "saleMonth": 0,
    "cardAlliance": "NONE",
    "joinIP": "61.77.11.203",
    "browser": None,
    "gift": None,
    "addService": "LRZ0000076|LRZ0002225|LRZ0000368",
    "imei": "359222390655071",
    "imei2": "359742770655078",
    "eid": "89043051202200836223005271865869",
    "memorySize": "512GB",
    "macAddress": None,
    "joinNum": "5303|0219|0159",
    "moveNum": "010",
    "joinTelco": "LGT",
    "moveTelco": None,
    "moveTelcoNm": None,
    "modelNM": "OMD-SM-F731N512",
    "moveAuth": None,
    "modelSerial": "R3CW70K12RB",
    "userMemo": None,
    "adminMemo": None,
    "pwd": "14E8E8DAC3E616DB5A2C2756A51654CC5DBA54BC9A6C216493255DB2215DB538",
    "agentID": "UCP13102",
    "status": "T",
    "serviceType": "2",
    "basicChk": None,
    "phoneFlag": None,
    "userPhNum": "01086125303",
    "phColor": None,
    "phMonType": 0,
    "email": "ckh5303@hanmail.net",
    "addrZip": "16708",
    "addrMain": "경기 수원시 영통구 영통로 498",
    "addrSub": "황골마을 주공 1단지 156동 501호",
    "modelCompanyID": None,
    "moveAuthNum": None,
    "nationality": None,
    "joinUsimType": None,
    "userBirth": "19670219",
    "hubSeq": None,
    "agentType": "BONSA",
    "promoSeq": None,
    "agentName": None,
    "banStatus": None,
    "waybillno": None,
    "receiptType": "S",
    "openingSerial": None,
    "serviceAccount": None,
    "serviceNumber": None,
    "openDlvType": None,
    "siteEventCD": None,
    "networkID": "4G",
    "selfSeq": None,
    "sendEmail": "Y",
    "planNM": "[L] 100분1GB+",
    "selfB2cDtStr": None,
    "selfStep": None,
    "authBean": {
        "serviceJoinSeq": "13188515",
        "userNm": "최경희",
        "userSsn": "Pafmg7cL4/mrh/HREN3jTw==",
        "idCard": "D",
        "authCode": "mTxId_17328520658981595",
        "authType": "K",
        "juminValid": None,
        "driverNum": "U25TnL5otvcDMP7NHmF6Wg==",
        "driverValid": "wWupcZip945lSs01JTjmSQ==",
        "userCI": "1bgJ54cl3fs15okH/wRd9cml5CULp5uxUVOpahDchbITPeQxEnZE9skIv3qltdvHnsy75U/S3yDcSfQuYxeDEg==",
        "userDI": None,
        "ip": None,
        "userPhNum": None,
        "etc": "3FRXxzm0/lDNSgJd8zIpqtUo+0AX5iznuO/GWaWY3d0Om8+oWLAyODci739LJgqG",
        "userSsnDecrypt": "670219-2031610",
        "driverNumDecrypt": "11-92-855238-50",
        "juminValidDecrypt": None,
        "driverValidDecrypt": "2024-05-03",
        "delDate": None
    },
    "billBean": {
        "serviceJoinSeq": "13188515",
        "billType": "BILL",
        "bankCD": None,
        "bankNum": None,
        "cardCD": "12",
        "cardNum": "VBRYSOOS1WmHA8GSUrOGDGiCnmh267ktpJdwCC/OjVE=",
        "cardValid": "prEiiM/xibB6csIx+kH68w==",
        "cmsBankCD": None,
        "cmsBankNum": None,
        "cmsChargeAmt": 0,
        "cmsMinAmt": 0,
        "cmsMonDay": 0,
        "cmsAgree": "Y",
        "cmsType": None,
        "chargePay": "C",
        "userNM": "최경희",
        "userSsn": "Pafmg7cL4/mrh/HREN3jTw==",
        "bankNumDecrypt": None,
        "cardNumDecrypt": "5188-3100-5147-8135",
        "cmsBankNumDecrypt": None,
        "userSsnDecrypt": "670219-2031610",
        "cardValidDecrypt": "12/28",
        "cardNumMasking": "5188**********35",
        "bankNumMasking": None,
        "delDate": None
    },
    "parentBean": None,
    "dlvBean": None,
    "payBean": None,
    "agreeBean": {
        "serviceJoinSeq": "13188515",
        "agree01": "Y",
        "agree02": "Y",
        "agree03": "Y",
        "agree04": "Y",
        "agree05": "Y",
        "agree06": "Y",
        "agree07": "Y",
        "agree08": None,
        "agree09": None,
        "agree10": None,
        "regDate": None
    },
    "promoList": None,
    "subBean": None,
    "trmMdlCd": None,
    "trmSrno": None,
    "trmMdlNm": None,
    "regDate": "2024-11-29 12:51:04",
    "userCi": "1bgJ54cl3fs15okH/wRd9cml5CULp5uxUVOpahDchbITPeQxEnZE9skIv3qltdvHnsy75U/S3yDcSfQuYxeDEg==",
    "rsvCtn": None,
    "mgate": None,
    "externalRefCode": None,
    "selfNumPattern": "0159"
}

ctns = []

for i in range(0, 10000):
    data['selfNumPattern'] = f"{i:04d}"
    response = requests.post(url, headers=headers, json=data)
    response.raise_for_status()
    res_json = response.json()
    if res_json.get('entity'):
        for ctn in res_json['entity']['bcNum']:
            ctns.append(ctn['ctn'])
    time.sleep(1)
    # data['selfNumPattern'] = str(f{%04d} % i)
    
ctns.sort()
print(ctns)

# print(response.status_code)
# print(response.json())