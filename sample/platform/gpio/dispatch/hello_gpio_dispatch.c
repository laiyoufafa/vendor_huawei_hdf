/* Copyright 2020 Huawei Device Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gpio_if.h"
#include "hdf_log.h"
#include "hdf_base.h"

#define HDF_LOG_TAG hello_gpio_dispatch
#define GPIO_PIN 11

int main()
{
    uint16_t dir;
    uint16_t val;
    if (GpioOpen() != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: GpioOpen failed", __func__);
        return HDF_FAILURE;
    }
    if (GpioSetDir(GPIO_PIN, GPIO_DIR_IN) != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: GpioSetDir failed, gpio %{public}u, dir %{public}u", __func__, GPIO_PIN, GPIO_DIR_IN);
        return HDF_FAILURE;
    }
    if (GpioWrite(GPIO_PIN, GPIO_VAL_HIGH) != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: GpioWrite failed, gpio %{public}u, val %{public}u", __func__, GPIO_PIN, GPIO_VAL_HIGH);
        return HDF_FAILURE;
    }
    if (GpioGetDir(GPIO_PIN, &dir) != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: GpioGetDir failed, gpio %{public}u", __func__, GPIO_PIN);
        return HDF_FAILURE;
    }
    if (GpioRead(GPIO_PIN, &val) != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: GpioRead failed, gpio %{public}u", __func__, GPIO_PIN);
        return HDF_FAILURE;
    }
    if (GpioClose() != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: GpioClose failed", __func__);
        return HDF_FAILURE;
    }
    HDF_LOGD("GPIO %{public}u direction is set to %{public}u, value is set to %{public}u", GPIO_PIN, dir, val);
    return HDF_SUCCESS;
}