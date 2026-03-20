# 🍬 CandyStore — Sistema de Punto de Venta en C

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Terminal](https://img.shields.io/badge/Terminal-4EAA25?style=for-the-badge&logo=gnubash&logoColor=white)
![POS System](https://img.shields.io/badge/Sistema-Punto%20de%20Venta-pink?style=for-the-badge)

> **Sistema completo de administración para una dulcería — desarrollado en C.**  
> Registra ventas, genera tickets de compra, controla tu inventario y mantén el negocio en orden, todo desde la terminal.

</div>

---

## 🎯 ¿Qué problema resuelve?

Cualquier negocio necesita controlar lo que vende y lo que tiene. CandyStore es un sistema de **punto de venta** funcional que cubre el ciclo completo de una venta: desde revisar el inventario disponible, registrar los productos que se venden, calcular el total y generar un ticket imprimible — implementado completamente en **C**, sin bases de datos externas.

---

## 🛒 Funcionalidades

| Módulo | Función | Descripción |
|---|---|---|
| 💰 **Ventas** | Registrar venta | Selecciona productos y cantidades para una venta |
| 🧾 **Tickets** | Generar ticket | Imprime en pantalla el comprobante detallado de la venta |
| 📦 **Inventario** | Ver inventario | Lista todos los productos con stock y precio actual |
| ✏️ **Inventario** | Modificar producto | Actualiza precio o cantidad disponible de un producto |
| ➕ **Inventario** | Agregar producto | Registra un nuevo dulce o producto al catálogo |
| 🗑️ **Inventario** | Eliminar producto | Retira un producto del catálogo |
| 📊 **Reportes** | Resumen de ventas | Muestra el total vendido en la sesión |

---



---

## 🏗️ Aspectos técnicos destacados

- ✅ **Persistencia de datos** — el inventario se guarda en archivo `.txt` y se carga al iniciar
- ✅ **Manejo de memoria dinámica** con structs y punteros
- ✅ **Modularización** clara separando inventario, ventas y tickets
- ✅ **Validación de entradas** — controla stock insuficiente y entradas inválidas
- ✅ **Aritmética de punto flotante** para precios e impuestos

---



¿Dudas o mejoras? Escríbeme: **sjared912@gmail.com** · [GitHub](https://github.com/Jesm31)
