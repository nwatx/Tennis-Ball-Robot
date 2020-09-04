
//...... exporting 9990 data values, starting at position=10
float sampPeriod=0.00139; // sec

 enum {ND=991};
 int adcA[ND] ={ 
 1273, 1270, 1276, 1269, 1262, 1253, 1245, 1240, 1236, 1212, 1204, 1189, 1155, 1147, 1143, 1131, 1127, 1114, 1112, 1110,
 1121, 1116, 1120, 1124, 1119, 1129, 1131, 1145, 1151, 1166, 1164, 1177, 1189, 1192, 1207, 1226, 1231, 1244, 1250, 1253,
 1269, 1280, 1269, 1272, 1279, 1275, 1274, 1286, 1270, 1259, 1257, 1251, 1245, 1239, 1221, 1215, 1197, 1189, 1180, 1175,
 1162, 1149, 1134, 1141, 1132, 1127, 1117, 1114, 1105, 1105, 1115, 1108, 1112, 1122, 1133, 1137, 1150, 1156, 1161, 1170,
 1189, 1223, 1236, 1235, 1255, 1257, 1264, 1266, 1271, 1279, 1272, 1273, 1290, 1275, 1266, 1271, 1259, 1251, 1217, 1207,
 1204, 1192, 1175, 1173, 1163, 1152, 1144, 1133, 1134, 1124, 1115, 1131, 1111, 1115, 1119, 1114, 1117, 1125, 1135, 1132,
 1147, 1155, 1169, 1173, 1185, 1204, 1200, 1215, 1227, 1237, 1248, 1260, 1260, 1266, 1272, 1279, 1275, 1290, 1230, 1273,
 1267, 1271, 1264, 1252, 1251, 1238, 1228, 1212, 1210, 1163, 1159, 1151, 1152, 1128, 1124, 1121, 1112, 1111, 1113, 1115,
 1116, 1111, 1123, 1128, 1136, 1144, 1143, 1154, 1160, 1173, 1191, 1202, 1202, 1216, 1233, 1243, 1248, 1259, 1258, 1266,
 1280, 1273, 1273, 1271, 1275, 1279, 1263, 1257, 1270, 1252, 1237, 1231, 1223, 1217, 1203, 1155, 1183, 1175, 1155, 1152,
 1153, 1137, 1123, 1123, 1123, 1113, 1112, 1113, 1117, 1120, 1116, 1119, 1123, 1131, 1141, 1155, 1164, 1207, 1213, 1228,
 1233, 1248, 1250, 1256, 1267, 1272, 1271, 1275, 1275, 1276, 1272, 1268, 1270, 1264, 1256, 1242, 1235, 1225, 1214, 1202,
 1195, 1184, 1171, 1164, 1149, 1144, 1133, 1128, 1124, 1120, 1119, 1114, 1106, 1109, 1119, 1120, 1126, 1131, 1128, 1138,
 1151, 1165, 1179, 1181, 1195, 1215, 1209, 1229, 1247, 1244, 1253, 1258, 1263, 1271, 1277, 1271, 1275, 1283, 1278, 1269,
 1277, 1259, 1256, 1247, 1239, 1217, 1187, 1183, 1170, 1139, 1151, 1142, 1126, 1130, 1124, 1120, 1111, 1111, 1111, 1116,
 1111, 1137, 1127, 1127, 1135, 1148, 1159, 1168, 1173, 1185, 1203, 1202, 1217, 1231, 1237, 1241, 1251, 1259, 1262, 1280,
 1277, 1273, 1275, 1274, 1272, 1263, 1260, 1263, 1241, 1239, 1223, 1221, 1212, 1198, 1185, 1182, 1160, 1155, 1148, 1146,
 1136, 1115, 1127, 1118, 1111, 1101, 1108, 1113, 1102, 1115, 1123, 1128, 1135, 1143, 1149, 1193, 1210, 1226, 1223, 1234,
 1247, 1255, 1261, 1275, 1273, 1268, 1279, 1277, 1282, 1280, 1267, 1267, 1257, 1253, 1242, 1247, 1222, 1213, 1208, 1195,
 1188, 1186, 1163, 1155, 1146, 1135, 1129, 1151, 1121, 1111, 1111, 1110, 1107, 1117, 1119, 1120, 1127, 1134, 1142, 1154,
 1160, 1171, 1184, 1188, 1215, 1213, 1221, 1236, 1242, 1247, 1268, 1262, 1267, 1274, 1278, 1274, 1273, 1276, 1275, 1265,
 1269, 1257, 1268, 1243, 1199, 1194, 1181, 1163, 1155, 1149, 1142, 1127, 1123, 1119, 1119, 1114, 1111, 1115, 1121, 1129,
 1135, 1147, 1151, 1155, 1165, 1175, 1194, 1191, 1208, 1221, 1225, 1240, 1247, 1257, 1264, 1264, 1269, 1275, 1291, 1276,
 1271, 1271, 1267, 1260, 1255, 1246, 1240, 1226, 1217, 1207, 1205, 1184, 1171, 1160, 1156, 1150, 1125, 1129, 1131, 1120,
 1117, 1115, 1105, 1108, 1110, 1119, 1119, 1129, 1128, 1137, 1171, 1185, 1194, 1203, 1215, 1227, 1237, 1251, 1248, 1255,
 1263, 1235, 1268, 1291, 1279, 1276, 1273, 1270, 1257, 1277, 1260, 1243, 1237, 1234, 1207, 1199, 1198, 1189, 1176, 1162,
 1154, 1154, 1176, 1134, 1127, 1121, 1120, 1121, 1106, 1107, 1116, 1119, 1129, 1127, 1133, 1141, 1152, 1155, 1166, 1182,
 1188, 1198, 1210, 1227, 1232, 1241, 1246, 1257, 1269, 1266, 1273, 1290, 1280, 1275, 1275, 1278, 1266, 1267, 1257, 1225,
 1215, 1200, 1187, 1183, 1173, 1160, 1138, 1141, 1147, 1131, 1121, 1119, 1115, 1110, 1110, 1137, 1115, 1123, 1124, 1128,
 1135, 1150, 1154, 1161, 1175, 1178, 1189, 1201, 1222, 1220, 1239, 1243, 1251, 1256, 1261, 1271, 1275, 1275, 1277, 1276,
 1259, 1273, 1269, 1263, 1250, 1247, 1237, 1222, 1212, 1203, 1195, 1184, 1171, 1177, 1156, 1138, 1137, 1131, 1125, 1124,
 1111, 1111, 1114, 1106, 1111, 1121, 1126, 1125, 1135, 1175, 1173, 1185, 1195, 1205, 1215, 1227, 1239, 1248, 1254, 1263,
 1282, 1269, 1271, 1274, 1278, 1265, 1261, 1271, 1268, 1250, 1261, 1247, 1240, 1222, 1211, 1201, 1196, 1180, 1167, 1163,
 1152, 1143, 1146, 1129, 1137, 1115, 1113, 1106, 1114, 1104, 1121, 1119, 1127, 1126, 1140, 1150, 1157, 1162, 1174, 1187,
 1193, 1211, 1217, 1226, 1238, 1248, 1253, 1301, 1274, 1266, 1271, 1273, 1278, 1281, 1279, 1269, 1267, 1240, 1227, 1221,
 1205, 1196, 1191, 1176, 1199, 1158, 1149, 1137, 1136, 1130, 1116, 1116, 1111, 1110, 1151, 1113, 1115, 1118, 1133, 1136,
 1139, 1147, 1154, 1164, 1173, 1183, 1209, 1208, 1215, 1226, 1244, 1241, 1252, 1274, 1265, 1272, 1271, 1279, 1279, 1279,
 1279, 1272, 1259, 1257, 1257, 1244, 1232, 1223, 1220, 1202, 1163, 1156, 1141, 1138, 1140, 1126, 1121, 1109, 1112, 1111,
 1119, 1114, 1112, 1117, 1140, 1149, 1160, 1175, 1181, 1191, 1203, 1215, 1220, 1229, 1244, 1259, 1268, 1274, 1272, 1279,
 1267, 1272, 1267, 1265, 1271, 1271, 1248, 1236, 1215, 1221, 1205, 1215, 1193, 1183, 1167, 1151, 1154, 1143, 1129, 1126,
 1116, 1116, 1112, 1109, 1107, 1111, 1119, 1121, 1138, 1147, 1139, 1144, 1156, 1167, 1182, 1192, 1197, 1207, 1221, 1231,
 1239, 1241, 1255, 1265, 1269, 1267, 1271, 1277, 1271, 1274, 1273, 1275, 1251, 1245, 1231, 1223, 1224, 1205, 1185, 1182,
 1174, 1166, 1141, 1157, 1135, 1130, 1118, 1115, 1115, 1112, 1107, 1111, 1111, 1116, 1109, 1122, 1135, 1143, 1145, 1156,
 1157, 1184, 1188, 1199, 1215, 1229, 1224, 1251, 1246, 1257, 1264, 1263, 1280, 1273, 1279, 1276, 1275, 1274, 1270, 1256,
 1252, 1247, 1239, 1222, 1203, 1207, 1201, 1179, 1167, 1153, 1157, 1143, 1137, 1124, 1129, 1119, 1118, 1112, 1109, 1111,
 1116, 1134, 1141, 1146, 1163, 1175, 1177, 1189, 1203, 1212, 1220, 1234, 1240, 1250, 1253, 1263, 1265, 1279, 1272, 1274,
 1278, 1277, 1270, 1275, 1263, 1257, 1234, 1236, 1228, 1217, 1216, 1198, 1198, 1187, 1179, 1157, 1147, 1145, 1129, 1127,
 1129, 1113, 1111, 1109, 1140, 1114, 1103, 1122, 1120, 1126, 1143, 1145, 1152, 1167, 1172, 1186, 1203, 1203, 1221, 1229,
 1232, 1240, 1255, 1261, 1253, 1268, 1275, 1274, 1273, 1270, 1257, 1251, 1245, 1245, 1226, 1215, 1210, 1202, 1183, 1185,
 1166, 1152, 1149, 1141, 1132, 1119, 1119, 1115, 1118, 1102, 1110,
 }; /**/
//...... end of raw data

