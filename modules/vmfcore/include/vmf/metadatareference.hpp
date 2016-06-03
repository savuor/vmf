/* 
 * Copyright 2015 Intel(r) Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http ://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*!
* \file metadatareference.hpp
* \brief %Reference class header file
*/

#ifndef __VMF_METADATA_REFERENCE_H__
#define __VMF_METADATA_REFERENCE_H__

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#include "metadatadesc.hpp"
#include "metadata.hpp"

namespace vmf
{
class Metadata;

/*!
 * \class Reference
 * \brief The class representing a reference from one metadata record to another
 */
class VMF_EXPORT Reference
{
private:
    std::shared_ptr<ReferenceDesc> desc;
    std::weak_ptr<Metadata>  md;

public:

    Reference();

    Reference(std::shared_ptr<ReferenceDesc>& desc, std::weak_ptr<Metadata>& md);
    Reference(std::shared_ptr<ReferenceDesc>& desc, const std::shared_ptr<Metadata>& md);

    ~Reference();

    std::weak_ptr<Metadata> getReferenceMetadata() const;
    std::shared_ptr<ReferenceDesc> getReferenceDescription() const;
    void setReferenceMetadata(const std::shared_ptr<Metadata>& spMetadata);
};

}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* __VMF_METADATA_REFERENCE_H__ */
